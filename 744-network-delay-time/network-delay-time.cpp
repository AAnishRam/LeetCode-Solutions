class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = INT_MIN;

        distance[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;

                if(dist + wt < distance[adjNode])
                {
                    // ans = max(ans, min(distance[adjNode], dist + wt));
                    distance[adjNode] = dist + wt;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        for(int i=1;i<n+1;i++)
        {
            if(i != k)
                ans = max(ans, distance[i]);
            
        }
        

        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};