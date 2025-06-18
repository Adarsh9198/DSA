class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int>sum(maxVal+1,0);
        // sum[i] = total points milenge agar hum i ko select karte hain
        // jaise agar 2 baar 3 aaya hai toh sum[3] = 3+3 = 6
        //[2,2,3,3,3,4]=sum_of_each->[0,0,4,9,4]
        for(int i=0;i<n;i++){
            sum[nums[i]]+=nums[i];
        }
        // agar hum sum[i] choose karte hain toh sum[i-1] ko skip karna padega
        // dp[i] = i tak ke max points
        vector<int>dp(maxVal+1,0);
        dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        for(int i=2;i<=maxVal;i++){
            // do options:
            // 1. current i lo -> sum[i] + dp[i-2]
            // 2. current i na lo -> dp[i-1]
            dp[i]=max(sum[i]+dp[i-2],dp[i-1]);
        }
        return dp[maxVal];
    }
};