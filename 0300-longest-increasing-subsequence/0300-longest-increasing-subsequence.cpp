class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<int> dp(n,1);
        dp[0]=1;
        
        for(int curr=1;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[prev]<nums[curr]){
                    dp[curr]=max (dp[curr],1+dp[prev]);
                    ans=max(ans,dp[curr]);
                }
            }
        }
        
        return ans;
    }
};