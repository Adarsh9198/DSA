class Solution {
public:
    typedef pair<int,int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>result;
        priority_queue<p,vector<p>>pq;
        for(int i=0;i<n;i++){
            int diff=abs(x-arr[i]);
            pq.push({diff,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            int num=pq.top().second;
            result.push_back(num);
            pq.pop();
        }
        sort(result.begin(),result.end());
        return result;
    }
};