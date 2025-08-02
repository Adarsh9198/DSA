class Solution {
public:
    //Dijkstra Algorithm Problem
    //T.C : O(((V+E)*log(V)) //log (v) for push,pop op and O(v+E) traversal in graph
    //S.C : O(V+E)   map 
    typedef pair<long,long>P;
    const int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<P,vector<P>,greater<P>>pq;//min heap
        vector<long long>result(n,LLONG_MAX);//pehle sab pr pahucne ka dist infinite le liye
        vector<int>pathCount(n,0);
        result[0]=0;
        pathCount[0]=1;//0 se 0 jaane ka 1 way
        pq.push({0,0});
        while(!pq.empty()){
            long long currTime=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            for(auto &vec:adj[currNode]){
                int adjNode  = vec.first;
                int roadTime = vec.second;
                if (currTime + roadTime < result[adjNode]) {
                    result[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.push({result[adjNode], adjNode});
                } else if (currTime + roadTime == result[adjNode]) {
                    pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
                }
            }
        }
        return pathCount[n-1];
    }
};