class Solution {
private:
    int paths(int row,int col,vector<vector<int>> &dp){
        if(row==dp.size()-1 && col==dp[0].size()-1) return 1;

        if(dp[row][col]!=-1) return dp[row][col];

        int a=0,b=0;

        if(row+1<dp.size() ) a=paths (row+1,col,dp);

        if(col+1<dp[0].size()) b=paths (row,col+1,dp);

        return dp[row][col]=a+b;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return paths (0,0,dp);
    }
};