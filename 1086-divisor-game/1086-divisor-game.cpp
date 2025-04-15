class Solution {
public:
    bool helper(int n, bool alice,vector<vector<int>> &dp){
        if(n==1) return alice;

        if(dp[n][alice]!=-1) return dp[n][alice];
        int lim=sqrt(n);

        for(int i=1;i<=lim;i++){
            if(n%i) continue;
            if(alice){
                if(!helper(n-i,!alice,dp)) return dp[n][alice]=false;
                return dp[n][alice]=true;
            } 
            else{
                if( helper(n-i,!alice,dp) ) return dp[n][alice]=true;
                return dp[n][alice]=false;
            } 
        }
        return false;
    }
    bool divisorGame(int n) {
        vector<vector<int>> dp(n+1,vector<int> (2,-1));

        return !helper(n, true,dp);
    }
};