class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int> &ans,int i,vector<vector<int>> &allSubsets){
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        //include
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allSubsets);
        //exclude
        ans.pop_back();
        int idx=i+1;
        //agar duplicate ek baar exclude ho gya toh aage bhi exclude hi hota rahega 
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        getAllSubsets(nums,ans,idx,allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allSubsets;
        sort(nums.begin(),nums.end());//saare duplicate elements ek saath aa jaaye
        getAllSubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
};