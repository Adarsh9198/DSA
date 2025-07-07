class Solution {
public:
    int n;
    int solve(vector<vector<int>>& events,int idx,int k,vector<vector<int>> &dp){
        if(idx>=n || k==0){
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        int start=events[idx][0];
        int end=events[idx][1];
        int value=events[idx][2];
        int skip=solve(events,idx+1,k,dp);
        //linear search-->T.C=>(n+1)(k+1)* O(n)
        int j=idx+1;
        for(;j<events.size();j++){
            if(events[j][0]>events[idx][1]) break;
        }
        int take=value +solve(events,j,k-1,dp);

        return dp[idx][k]=max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(events,0,k,dp);
    }
};