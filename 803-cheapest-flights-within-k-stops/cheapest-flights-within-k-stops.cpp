class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp_dist = distances;
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (distances[u] != INT_MAX) {
                    temp_dist[v] = min(temp_dist[v], distances[u] + price);
                }
            }
            distances = temp_dist;
        }

        if (distances[dst] == INT_MAX) {
            return -1;
        }
        
        return distances[dst];
    }
};