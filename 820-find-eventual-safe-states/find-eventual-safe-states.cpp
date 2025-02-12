class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int> &visited, 
    vector<int> &pathVisited, vector<int> &isSafeNode)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto adjNode : graph[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, graph, visited, pathVisited, isSafeNode) == true)
                {
                    return true;
                }
            }
            else if(pathVisited[adjNode])
            {
                    return true;
            }
        }

        isSafeNode[node] = 1;
        pathVisited[node] = 0;
        return false;


    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n = graph.size();
        // vector<int> visited(n, 0);
        // vector<int> pathVisited(n, 0);
        // vector<int> isSafeNode(n, 0);

        // for(int i = 0; i < n; i++)
        // {
        //     if(!visited[i])
        //         dfs(i, graph, visited, pathVisited, isSafeNode);
        // }

        // vector<int> ans;

        // for(int i = 0; i < n; i++)
        // {
        //     if(isSafeNode[i])
        //         ans.push_back(i);
        // }

        // return ans;


        // we can also use topo sort here
        // first reverese the edges 
        // then perform topo sort

        int n = graph.size();
        vector<vector<int>> graphRev(n);

        for(int node = 0; node < n; node++)
        {
            for(auto adjNode : graph[node])
            {
                graphRev[adjNode].push_back(node);
            }
        }

        vector<int> inDegree(n, 0);
        queue<int> q;
        vector<int> topoSort;

        for(int node = 0; node < n; node++)
        {
            for(auto adjNode : graphRev[node])
            {
                inDegree[adjNode]++;
            }
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

            for(auto adjNode : graphRev[node])
            {
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        sort(topoSort.begin(), topoSort.end());

        return topoSort;

    }
};