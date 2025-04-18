class Solution {
public:
    int findMaxProfit(vector<int>& prices,int numTransaction,int index,vector<vector<int>>& dp){
      if(index>=prices.size() || numTransaction==0 ) return 0;

      if(dp[index][numTransaction]!=-1) return dp[index][numTransaction];

      if(numTransaction%2==0){
        int ans =  -prices[index] + findMaxProfit(prices,numTransaction-1,index+1,dp);
        ans =  max(findMaxProfit(prices,numTransaction,index+1,dp), ans);
        return dp[index][numTransaction] = ans;
      }
      else{
        int ans = prices[index] + findMaxProfit(prices,numTransaction-1,index+1,dp);
        ans=max (findMaxProfit(prices,numTransaction,index+1,dp),ans);
        return dp[index][numTransaction] = ans;
      }
      return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
      vector<vector<int>> dp(prices.size(),vector<int>(2*k+1,-1));
      return findMaxProfit(prices,2*k,0,dp);
    }
};