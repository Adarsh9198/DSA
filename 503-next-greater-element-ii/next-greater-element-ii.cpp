class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){//kyoki circular hai isliye
            int idx=i%n;//original index 
            while(!st.empty() && nums[st.top()]<=nums[idx]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ans[idx]=nums[st.top()];
                }
            }
            st.push(idx);
        }
        return ans;
    }
};