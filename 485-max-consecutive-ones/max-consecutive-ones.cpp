class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        // int right=0;
        // int left=0;
        int count=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
            if(nums[i]==0) count=0;
             maxi=max(maxi,count);

        }
        // maxi=max(maxi,count);
        return maxi;
    }
};