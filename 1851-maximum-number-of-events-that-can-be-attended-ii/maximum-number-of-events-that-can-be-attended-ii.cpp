class Solution {
public:
    long long n;
    int getNext(vector<vector<int>>& events,int l,int currJobEnd){
        int r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>currJobEnd){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
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
        // int j=idx+1;
        // for(;j<events.size();j++){
        //     if(events[j][0]>events[idx][1]) break;
        // }

        // using upper_bound fn i.e binary search  to find idx of evnt with start>end
        // vector<int>temp={end,INT_MAX,INT_MAX};
        // int j=upper_bound(events.begin()+idx+1,events.end(),temp) -events.begin();
        // idx pr khade h toh uske baad se start kiya.....aur subtract kiya kyoki idx chahiye 

        int NextIdx=getNext(events,idx+1,events[idx][1]);
        int take=value +solve(events,NextIdx,k-1,dp);

        return dp[idx][k]=max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(events,0,k,dp);
    }
};