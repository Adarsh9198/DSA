class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int max_diff=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                int diff=nums[j]-nums[i];
                max_diff=max(max_diff,diff);
                }
            }
        }
        return max_diff;
    }
};