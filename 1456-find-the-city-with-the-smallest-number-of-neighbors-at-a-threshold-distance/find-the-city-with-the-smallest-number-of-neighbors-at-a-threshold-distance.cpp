class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int resultCity=-1;
        int minReachableCount=n+1;
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [currentDist, currentNode] = pq.top();
                pq.pop();
                if (currentDist > dist[currentNode]) {
                    continue;
                }
                for (const auto& neighborPair : adj[currentNode]) {
                    int neighborNode = neighborPair.first;
                    int edgeWeight = neighborPair.second;
                    if (dist[currentNode] != INT_MAX && dist[currentNode] + edgeWeight < dist[neighborNode]) {
                        dist[neighborNode] = dist[currentNode] + edgeWeight;
                        pq.push({dist[neighborNode], neighborNode});
                    }
                }
            }
            int currentReachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[j] <= distanceThreshold) {
                    currentReachableCount++;
                }
            }
            if (currentReachableCount <= minReachableCount) {
                minReachableCount = currentReachableCount;
                resultCity = i;
            }
        }
        return resultCity;
    }
};