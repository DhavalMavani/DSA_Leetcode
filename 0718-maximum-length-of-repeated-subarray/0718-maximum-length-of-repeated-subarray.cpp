class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(),ans=0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(nums1[i]==nums2[j] ) dp[i][j]=1+dp[i+1][j+1];
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};