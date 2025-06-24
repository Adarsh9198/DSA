class Solution {
public:
    bool solve(string& s, int i, int j,vector<vector<int>>&dp) {
        if (i >= j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1,dp);
        }
        return dp[i][j]=0;//0 means false    
    }
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxLen=INT_MIN;
        int start_point=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start_point=i;
                    }
                }
            }
        }
        return s.substr(start_point,maxLen);
    }
};