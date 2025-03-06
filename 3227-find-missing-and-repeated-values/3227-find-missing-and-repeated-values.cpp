class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> ans;

        vector<bool> arr(n*n+1,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[grid[i][j]] ) ans.emplace_back(grid[i][j] );
                arr[grid[i][j]]=true;
            }
        }

        for(int k=1;k<=n*n;k++){
            if(!arr[k]){
                ans.emplace_back(k);
                return ans;
            } 
        }
        return ans;
    }
};