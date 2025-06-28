class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int num:st){
            minHeap.push(num);
            if(minHeap.size()>3){
                minHeap.pop();
            }
        }
        if(minHeap.size()<3){
            while(minHeap.size()>1){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};