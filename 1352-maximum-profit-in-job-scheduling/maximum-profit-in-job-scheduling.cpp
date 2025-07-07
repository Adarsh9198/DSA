class Solution {
public:
    int n;
    int getNext(vector<vector<int>>&job,int l,int currJobEnd){
        int r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(job[mid][0]>=currJobEnd){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&job,int idx,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int val=job[idx][2];
        int skip=solve(job,idx+1,dp);

        int nextIdx=getNext(job,idx+1,job[idx][1]);
        int take= val+ solve(job,nextIdx,dp);

        return dp[idx]=max(skip,take);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         n=startTime.size();
        vector<vector<int>> job(n,vector<int>(3,0));//{start,end,profit}
        for(int i=0;i<n;i++){
            job[i][0]=startTime[i];
            job[i][1]=endTime[i];
            job[i][2]=profit[i];
        }
        //sort on the basis of start time
        sort(job.begin(),job.end());
        vector<int>dp(n+1,-1);//only idx is changing
        return solve(job,0,dp);
    }
};