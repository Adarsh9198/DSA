class Solution {
public:
    bool topoLogicalSort(unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree){
        queue<int>que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
            while(!que.empty()){
                int u=que.front();
                que.pop();
                for(int &v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        que.push(v);
                        count++;
                    }
                }
            }
            return (count==n);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
        for(auto & vec:prerequisites){
            int a =vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            //arrow a pr ja rha h
            indegree[a]++;
        }
        //if cycle present then course not possible
        queue<int>que;
        return topoLogicalSort(adj,numCourses,indegree);
    }
};