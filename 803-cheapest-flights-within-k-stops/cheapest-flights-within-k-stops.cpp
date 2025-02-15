class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> prices(n, INT_MAX); // Stores the best price for each city
        queue<pair<int, pair<int, int>>> pq; // {stops, {cost, city}}
        pq.push({0, {0, src}});
        prices[src] = 0;

        while (!pq.empty()) {
            auto [stops, node] = pq.front();
            pq.pop();
            int price = node.first;
            int city = node.second;

            if (stops > k) continue; // We can take at most k stops

            for (auto& [nextCity, flightPrice] : adj[city]) {
                int newPrice = price + flightPrice;

                // We push into the queue if it's a better price for the given stop count
                if (newPrice < prices[nextCity]) {
                    prices[nextCity] = newPrice;
                    pq.push({stops + 1, {newPrice, nextCity}});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
