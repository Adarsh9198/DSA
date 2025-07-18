class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        //k se modulo lena hai toh 0 se k-1 remainder aa skta hai
        //row 0=>(nums[j]+nums[i])==0
        //row 1=>(nums[j]+nums[i])==1
        //row 2=>(nums[j]+nums[i])==2.....and so on
        vector<vector<int>>dp(k,vector<int>(n,1));
        int maxLen=1;

        //VARIANT OF LIS 
        //dp[mod][i]=length of longest sub till that index
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
               int mod= (nums[j]+nums[i])%k;

               dp[mod][i]=max(dp[mod][i],dp[mod][j]+1);
               maxLen=max(maxLen,dp[mod][i]);
            }
        }
        return maxLen;
    }
};