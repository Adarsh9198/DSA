class Solution {
public:
    void getPerms(vector<int>& nums,int idx,vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
            if(st.count(nums[i])) continue;//skip duplicates
            st.insert(nums[i]);
            
            swap(nums[idx],nums[i]);
            getPerms(nums,idx+1,ans);
            
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        getPerms(nums,0,ans);
        return ans;
    }
};