class Solution {
public:
    int findMaxProfit(vector<int>& prices,int numTransaction,int index,vector<vector<int>>& dp){
      if(index>=prices.size() || numTransaction==0 ) return 0;

      if(dp[index][numTransaction]!=-1) return dp[index][numTransaction];

      if(numTransaction%2==0){
        int a =  -prices[index] + findMaxProfit(prices,numTransaction-1,index+1,dp);
        int b =  findMaxProfit(prices,numTransaction,index+1,dp);
        return dp[index][numTransaction] = max(a,b);
      }
      else{
        int a = prices[index] + findMaxProfit(prices,numTransaction-1,index+1,dp);
        int b = findMaxProfit(prices,numTransaction,index+1,dp);
        return dp[index][numTransaction] = max(a,b);
      }
    }
    int maxProfit(int k, vector<int>& prices) {
      vector<vector<int>> dp(prices.size(),vector<int>(2*k+1,-1));
      return findMaxProfit(prices,2*k,0,dp);
    }
};