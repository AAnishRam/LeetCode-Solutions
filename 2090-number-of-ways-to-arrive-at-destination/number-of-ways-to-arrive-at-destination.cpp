class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);

        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while(!pq.empty())
        {
            int node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();

            for(auto it : adj[node])
            {
                int adjNode = it.first;
                long long adjWt = it.second;

                if(adjWt + wt < dist[adjNode])
                {
                    pq.push({adjWt + wt, adjNode});
                    dist[adjNode] = adjWt + wt;
                    ways[adjNode] = ways[node] % mod;
                }
                else if(adjWt + wt == dist[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }

            }
        }

        return ways[n - 1] % mod;


    }
};