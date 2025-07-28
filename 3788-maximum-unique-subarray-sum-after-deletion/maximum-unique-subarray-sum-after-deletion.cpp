class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int max_sumN=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0) max_sumN=max(max_sumN,nums[i]);
            if(nums[i]>0) st.insert(nums[i]);
        }
        int max_sumP=0;
        for(int num:st){
            max_sumP+=num;
        }
        if(max_sumP==0) return max_sumN;
        else return max_sumP;
    }
};