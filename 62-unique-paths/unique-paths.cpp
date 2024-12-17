class Solution {
public:

    int minPath(int i, int j, vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return dp[0][0] = 1;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int up = 0, left = 0;

        if(i-1>=0)
        up = minPath(i-1,j,dp);
        if(j-1>=0)
        left = minPath(i,j-1,dp);

        return dp[i][j]=up+left;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return minPath(m-1,n-1,dp);
    }
};