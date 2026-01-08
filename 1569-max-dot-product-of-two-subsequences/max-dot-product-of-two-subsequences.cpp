class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, vector<int> nums1, vector<int> nums2, int n, int m) {
        if(i >= n || j >= m) return INT_MIN;

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int pdt = nums1[i] * nums2[j];
        int include = pdt + max(0, solve(i+1, j+1, dp, nums1, nums2, n, m));
        int excludeFromFirstArray = solve(i+1, j, dp, nums1, nums2, n, m);
        int excludeFromSecondArray = solve(i, j+1, dp, nums1, nums2, n, m);

        return dp[i][j] = max(include, max(excludeFromFirstArray, excludeFromSecondArray));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n,vector<int>(m, INT_MIN));

        //bottom up
        // return solve(0, 0, dp, nums1, nums2, n, m);

        //top to bottom
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = nums1[i] * nums2[j];

                if(i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j] + max(0, dp[i-1][j-1]));
                }

                if(i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                if(j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};