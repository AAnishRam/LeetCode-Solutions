class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int>topoSort;
        vector<int>inDegree(n, 0);
        queue<int> q;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        for(int node = 0; node < n; node++)
        {
            for(auto adjNode : adj[node])
                inDegree[adjNode]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for(auto adjNode : adj[node])
            {
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        if(topoSort.size() == n)
            return topoSort;
        else
            return {};
    }
};