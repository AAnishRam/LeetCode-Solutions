class Solution {
public:
    
    //top down
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i == s1.length()) {
            int sum = 0;
            for(int it = j; it < s2.length(); it++) sum += (int)s2[it];
            return sum;
        }

        if(j == s2.length()) {
            int sum = 0;
            for(int it = i; it < s1.length(); it++) sum += (int)s1[it];
            return sum;
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = solve(i+1, j+1, s1, s2, dp);
        
        int n1 = s1[i] + solve(i+1, j, s1, s2, dp);
        int n2 = s2[j] + solve(i, j+1, s1, s2, dp);

        return dp[i][j] = min(n1, n2);
    }

    int minimumDeleteSum(string s1, string s2) {

        // vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), INT_MAX));
        // return solve(0, 0, s1, s2, dp);

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        for(int i=n-1; i>=0; i--) {
            dp[i][m] = dp[i+1][m] + s1[i];
        }

        for(int j=m-1; j>=0; j--) {
            dp[n][j] = dp[n][j+1] + s2[j];
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = min(dp[i+1][j]+s1[i], dp[i][j+1]+s2[j]);
            }
        }

        return dp[0][0];

    }
};