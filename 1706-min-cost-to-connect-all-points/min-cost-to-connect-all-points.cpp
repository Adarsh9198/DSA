class Solution {
public:
    typedef pair<int,int>P;
    int prims(vector<vector<P>>&adj,int v){
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>inMST(v,false);
        pq.push({0,0});//0 se 0 ka egde wt 0
        int sum=0;
        while(!pq.empty()){
            auto p=pq.top();//is p mei pair aayega (wt,node)
            pq.pop();
            int wt=p.first;
            int node=p.second;
            if(inMST[node]==true) continue;
            inMST[node]=true;//added in visited
            sum+=wt;
            for(auto &temp:adj[node]){
                int neighbour=temp.first;
                int neighbour_wt=temp.second;
                if(inMST[neighbour]==false){
                    pq.push({neighbour_wt,neighbour});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int v=points.size();//no of vertices
        vector<vector<P>>adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x2-x1)+abs(y2-y1);

                adj[i].push_back({j,d});//jo i se j ka distance hoga wahi j se i ka
                adj[j].push_back({i,d});
            }
        }
        return prims(adj,v);
    }
};