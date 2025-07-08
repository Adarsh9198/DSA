class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int> &ans,int idx,vector<vector<int>>&allSubsets){
        if(idx==nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        //include 
        ans.push_back(nums[idx]);
        getAllSubsets(nums,ans,idx+1,allSubsets);
        //exclude
        ans.pop_back();
        getAllSubsets(nums,ans,idx+1,allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allSubsets;
        getAllSubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
};