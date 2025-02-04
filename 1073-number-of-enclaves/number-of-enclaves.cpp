class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1,  0, -1};

        for(int i=0; i<4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            !visited[newRow][newCol] && grid[newRow][newCol] == 1)
                dfs(newRow, newCol, grid, visited);
        }
        
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0 ; i < m ; i++)
        {
            if(grid[0][i] == 1 && !visited[0][i])
                dfs(0, i, grid, visited);

            if(grid[n-1][i] == 1 && !visited[n-1][i])
                dfs(n-1, i, grid, visited);
        }

        for(int i=0; i<n; i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
                dfs(i, 0, grid, visited);
            if(grid[i][m-1] == 1 && !visited[i][m-1])
                dfs(i, m-1, grid, visited);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0 ;j<m;j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};