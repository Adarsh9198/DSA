class Solution {
public:
    //max sum subarray 
    int kadaneMax(vector<int>&nums){
        int n=nums.size();
        int currSum=nums[0];
        int best=nums[0];
        for(int i=1;i<n;i++){
            currSum=max(nums[i],currSum+nums[i]);
            best=max(best,currSum);
        }
        return best;
    }
    //min sum subarray 
    int kadaneMin(vector<int>&nums){
        int n=nums.size();
        int currSum=nums[0];
        int best=nums[0];
        for(int i=1;i<n;i++){
            currSum=min(nums[i],currSum+nums[i]);
            best=min(best,currSum);
        }
        return best;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int max_normal=kadaneMax(nums);
        int min_normal=kadaneMin(nums);
        //if all elements are negative
        if(max_normal<0) return max_normal;
        int max_wrap = total_sum - min_normal;
        return max(max_normal, max_wrap);
    }
};