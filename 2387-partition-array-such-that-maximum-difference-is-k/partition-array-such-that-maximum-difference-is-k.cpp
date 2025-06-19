class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]-s>k){
                s=nums[i];
                count++;
            }
        }
        return count;
    }
};