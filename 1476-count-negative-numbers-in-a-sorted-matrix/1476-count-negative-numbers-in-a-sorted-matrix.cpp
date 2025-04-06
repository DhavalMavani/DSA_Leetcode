class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), i=m-1,j=0, count=0;
        // start from bottom left
        
        while(i>=0 && j<n){
            if(grid[i][j] < 0){
                count += n-j; 
                i--;
            }
            else j=j+1;
        }       
        return count;   
    }
};
