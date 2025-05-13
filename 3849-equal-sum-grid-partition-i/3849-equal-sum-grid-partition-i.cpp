class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<long long>> dp(n,vector<long long>(m,0));

        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++) dp[0][i]+=dp[0][i-1]+grid[0][i];
        for(int i=1;i<n;i++) dp[i][0]+=dp[i-1][0]+grid[i][0];

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i][j];
            }
        }

        if(dp[n-1][m-1]%2!=0) return false;
        long long target=dp[n-1][m-1]/2;

        int l=0,r=n-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(dp[mid][m-1]==target ) return true;
            else if(dp[mid][m-1] > target) r=mid-1;
            else l=mid+1;
        }

        l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(dp[n-1][mid]==target ) return true;
            else if(dp[n-1][mid] > target) r=mid-1;
            else l=mid+1;
        }


        return false;
    }
};