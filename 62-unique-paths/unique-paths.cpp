class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1 ) return 1;
        if(i<0 || i>m-1 || j<0 || j>n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(m,n,i+1,j,dp);
        int down=solve(m,n,i,j+1,dp);

        return dp[i][j]=(right+down);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);//start from i=0 nad j=0
    }
};