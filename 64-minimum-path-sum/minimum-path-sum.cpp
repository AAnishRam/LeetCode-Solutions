class Solution {
public:

    int minPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
            return dp[i][j] = grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int up = INT_MAX;
        int left = INT_MAX;

        if(i-1>=0)
        up = grid[i][j] + minPath(i-1,j,grid,dp);
        if(j-1>=0)
        left = grid[i][j] + minPath(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return minPath(m-1,n-1,grid,dp);
    }
};