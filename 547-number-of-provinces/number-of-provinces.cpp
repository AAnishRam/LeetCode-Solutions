class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited (V,0);
        int count = 0;

        queue<int> q;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                count++;
                q.push(i);
                visited[i] = 1;

                while(!q.empty())
                {
                    int currNode = q.front();
                    q.pop();
                    for(int j = 0; j<isConnected[currNode].size(); j++)
                    {
                        if(!visited[j] && isConnected[currNode][j] == 1)
                        {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return count;
        
    }
};