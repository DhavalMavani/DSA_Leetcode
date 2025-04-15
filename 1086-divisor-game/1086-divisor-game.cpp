class Solution {
public:
    bool helper(int n,vector<int> &dp){
        if(n==1) return false;

        if(dp[n]!=-1) return dp[n];
        int lim=sqrt(n);
        for(int i=1;i<=lim;i++){
            if(n%i==0){
                if(!helper(n-i,dp)) return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);

        return helper(n,dp);
    }
};