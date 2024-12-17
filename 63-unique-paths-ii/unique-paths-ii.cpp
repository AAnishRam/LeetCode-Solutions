class Solution {
public:

int minPath(int i, int j, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid[i][j]==1)
            return dp[i][j] = 0;
        if(i==0 && j==0 )
        {
            return dp[0][0] = 1;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int up = 0, left = 0;

        if(i-1>=0 && obstacleGrid[i-1][j]!=1)
        up = minPath(i-1,j,dp,obstacleGrid);
        if(j-1>=0 && obstacleGrid[i][j-1]!=1)
        left = minPath(i,j-1,dp,obstacleGrid);

        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return minPath(m-1,n-1,dp,obstacleGrid);

    }
};