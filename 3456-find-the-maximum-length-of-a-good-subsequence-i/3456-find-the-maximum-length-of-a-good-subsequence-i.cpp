class Solution {
public:
    int helper(vector<int>& nums, int prevInd, int k,vector<vector<int>> &dp){
        int n=nums.size(),ans=0;
        if(dp[prevInd+1][k+1]!=-1) return dp[prevInd+1][k+1];
        for(int i=prevInd+1;i<n;i++){
            if(prevInd!=-1 && nums[i]==nums[prevInd]) ans=max(ans,1+helper(nums,i,k,dp) );
            else if(k>=0)  ans=max(ans, 1+helper(nums,i,k-1,dp));
        }
        return dp[prevInd+1][k+1]=ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(k+2,-1));
        return helper(nums, -1, k,dp);
    }
};