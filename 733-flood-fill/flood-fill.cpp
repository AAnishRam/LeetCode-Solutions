class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited = image;

        if(visited[sr][sc] == color)
            return visited;
        
        queue<pair<int, int>>q;
        q.push({sr, sc});
        visited[sr][sc] = color;

        int dr [] = {-1, 0, +1, 0};
        int dc [] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                visited[newRow][newCol] == image[sr][sc])
                {
                    visited[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }


        }

        return visited;

    }
};