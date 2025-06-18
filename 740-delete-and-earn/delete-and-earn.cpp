class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int>sum(maxVal+1,0);
        //[2,2,3,3,3,4]=sum_of_each->[0,0,4,9,4]
        for(int i=0;i<n;i++){
            sum[nums[i]]+=nums[i];
        }

        vector<int>dp(maxVal+1,0);
        dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        for(int i=2;i<=maxVal;i++){
            dp[i]=max(sum[i]+dp[i-2],dp[i-1]);
        }
        return dp[maxVal];
    }
};