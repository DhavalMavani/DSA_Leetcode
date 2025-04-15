class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid[0][0] ) return 0;
        int row=obstacleGrid.size(), col=obstacleGrid[0].size();
        if( obstacleGrid[row-1][col-1] ) return 0;

        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        dp[row-1][col]=1;

        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(!obstacleGrid[i][j]) dp[i][j]=(long long)dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];

    }
};