class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=nums2[st.top()];
            }
            st.push(i);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};