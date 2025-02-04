class Solution {
public:
    bool checkIsBipartite(vector<vector<int>>& graph, vector<int> &visited, int src) {
        queue<int> q;
        q.push(src);
        visited[src] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : graph[node]) {
                if(visited[it] == -1)
                {
                    visited[it] = visited[node] == 0 ? 1 : 0;
                    q.push(it);
                }
                else
                {
                    if(visited[node] == visited[it])
                        return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();


        //bipartite also means that no two adjacen nodes will have two colors let i use 0, 1 
        //for coloring and carry it on 
        
        vector<int>visited(n, -1);

        for(int i = 0; i<n; i++) {
            if(visited[i] == -1 && !checkIsBipartite(graph, visited, i))
                return false;
        }

        return true;

    }
};