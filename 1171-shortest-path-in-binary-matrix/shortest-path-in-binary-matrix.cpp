class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        q.push({{0, 0}, 0});
        visited[0][0] = 1;

        if(grid[0][0] == 1)
            return -1;

        int ans = INT_MAX;

        int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty())
        {
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;
            q.pop();
            
            if(r == n-1 && c == n-1)
            {
                ans = min(ans, dist);
                break;
            }

            for(int i=0;i<8;i++)
            {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                int newDist = dist + 1;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                grid[newRow][newCol] == 0 && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, newDist});
                }
            }


        }

        if(ans == INT_MAX)
            return -1;

        return ans + 1;
    }
};