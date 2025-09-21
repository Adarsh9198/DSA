class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(const auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int currDist=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            if(currDist>dist[currNode]){
                continue;
            }
            for(auto &neighbor:adj[currNode]){
                int neighNode=neighbor.first;
                int edgeWeight=neighbor.second;

                if(dist[currNode]!=INT_MAX && dist[currNode]+edgeWeight<dist[neighNode]){
                    dist[neighNode]=dist[currNode]+edgeWeight;
                    pq.push({ dist[neighNode],neighNode});
                }
            }
        }
        int maxTime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxTime=max(maxTime,dist[i]);
        }
        return maxTime;
    }
};