class Solution {
public:
    int calculatePath(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        int rs=grid.size(), cs=grid[0].size();
        if(row==rs-1 && col==cs-1) return grid[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int ans=10e7;

        if( row+1<rs) ans=min( calculatePath(grid,row+1,col,dp), ans);

        if( col+1<cs) ans=min( calculatePath(grid,row,col+1,dp), ans);

        return dp[row][col]=ans+grid[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return calculatePath(grid,0,0,dp);
    }
};