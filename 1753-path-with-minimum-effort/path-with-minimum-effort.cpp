class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>>q;
        q.push({0, 0});
        distance[0][0] = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                {
                    int newWeight = abs(heights[newRow][newCol] - heights[r][c]);
                    int maxEffort = max(distance[r][c], newWeight);
                    if (maxEffort < distance[newRow][newCol]) {
                        distance[newRow][newCol] = maxEffort;
                        q.push({newRow, newCol});
                    }

                }

            }


        }

        return distance[n-1][m-1];

    }
};