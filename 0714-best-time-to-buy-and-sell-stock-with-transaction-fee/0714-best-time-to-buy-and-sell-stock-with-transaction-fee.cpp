class Solution {
public:
    int solve(int index, bool canBuy,vector<int>& prices, int &fee, vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        if(dp[index][canBuy]!=-1) return dp[index][canBuy];
        if(canBuy){
            return dp[index][canBuy]=max(-prices[index]-fee + solve(index+1,!canBuy, prices,fee,dp), solve(index+1,canBuy, prices,fee,dp) );
        }
        else{
            return dp[index][canBuy]=max( prices[index] + solve(index+1,!canBuy, prices,fee,dp), solve(index+1,canBuy, prices,fee,dp) );
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,true,prices,fee,dp);
    }
};