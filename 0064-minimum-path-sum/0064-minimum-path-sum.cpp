class Solution {
public:
    int calculatePath(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row==grid.size()-1 && col==grid[0].size()-1) return grid[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int ans=10e7;

        if( row+1<grid.size()) ans=min( calculatePath(grid,row+1,col,dp), ans);

        if( col+1<grid[0].size()) ans=min( calculatePath(grid,row,col+1,dp), ans);

        return dp[row][col]=ans+grid[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return calculatePath(grid,0,0,dp);
    }
};