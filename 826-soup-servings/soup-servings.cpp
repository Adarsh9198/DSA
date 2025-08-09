class Solution {
public:
vector<pair<int,int>> ops = {{100, 0},{75, 25},{50, 50},{25, 75}};
    double solve(double A,double B,vector<vector<double>>&dp){
        if(A<=0 && B<=0) return 0.5;
        if(A<=0) return 1;
        if(B<=0) return 0;
        if(dp[A][B]!=-1.0) return dp[A][B];
        double prob=0;

        for(auto &p:ops){
            int A_taken=p.first;
            int B_taken=p.second;
            prob+=solve(A-A_taken,B-B_taken,dp);
        }
        return dp[A][B]=0.25*prob;
    }
    double soupServings(int n) {
        if(n>=5000) return 1.0;//Jaise jaise N badaa hoga A utni jaldi khaali ho jaayega
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));//since two variables are changing A & B
        
        return solve(n,n,dp);
    }
};