class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));

        //{{row, col}, min}
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }

        int mini = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int minutes = q.front().second;
            q.pop();

            mini = max(mini, minutes);

            for(int i=0; i<4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                int newMinutes = minutes + 1;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                visited[newRow][newCol] != 2 && grid[newRow][newCol] == 1)
                {
                    visited[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, newMinutes});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] != 2)
                    return -1;
            }
        }

        return mini;


    }
};