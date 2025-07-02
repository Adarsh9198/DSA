// class Solution {
// public:
//     //  BOTTOM-UP APPROACH
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         for(int i=2;i<n;i++){
//             cost[i]+=min(cost[i-1],cost[i-2]);
//         }
//         return min(cost[n-1],cost[n-2]);
//     }
// };

class Solution {
public:
    int solve(int i,vector<int>&cost,vector<int>&dp){
        if(i==0) return cost[0];
        if(i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        dp[i]=cost[i]+min(solve(i-1,cost,dp),solve(i-2,cost,dp));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};



