class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        vector<int>prices(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        // {steps, {cost, flightNumber}}
        pq.push({0, {0, src}});
        prices[src] = 0;

        while(!pq.empty())
        {
            auto iterator = pq.top();
            pq.pop();
            int step = iterator.first;
            int price = iterator.second.first;
            int flight = iterator.second.second;

            if (step > k) continue; 


            for(auto it : adj[flight])
            {
                int adjFlight = it.first;
                int adjPrice = it.second;

                int newPrice = price + adjPrice;

                if(newPrice < prices[adjFlight])
                {
                    prices[adjFlight] = newPrice;
                    pq.push({step+1, {newPrice, adjFlight}});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];

    }
};