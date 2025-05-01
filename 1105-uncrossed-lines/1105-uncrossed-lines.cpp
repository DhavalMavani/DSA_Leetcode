class Solution {
public:

    int helper(int i1, int i2, vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(i1==nums1.size() || i2==nums2.size()) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];
        
        int ans=helper(i1+1,i2,nums1,nums2,dp);
        ans=max(ans,helper(i1,i2+1,nums1,nums2,dp));
        if(nums1[i1]==nums2[i2]) ans=max(ans,1+helper(i1+1,i2+1,nums1,nums2,dp));

        return dp[i1][i2]=ans;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),-1));
        return helper(0,0,nums1,nums2,dp);
    }
};