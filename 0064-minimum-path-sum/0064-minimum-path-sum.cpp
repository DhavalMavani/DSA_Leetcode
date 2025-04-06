class Solution {
public:
    vector<int> arr={0,1,0};
    int calculatePath(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row==grid.size()-1 && col==grid[0].size()-1) return dp[row][col]=grid[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int ans=10e7;
        for(int i=0;i<2;i++){
            int a=row+arr[i];
            int b=col+arr[i+1];
            if( a>=0 && b>=0 && a<grid.size() && b<grid[0].size()){
                ans=min( calculatePath(grid,a,b,dp), ans);
            }
        }
        return dp[row][col]=ans+grid[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return calculatePath(grid,0,0,dp);
    }
};