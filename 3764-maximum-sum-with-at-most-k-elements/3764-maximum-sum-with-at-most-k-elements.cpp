class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long sum=0;
        int r=grid.size();
        if(k==0) return 0;
        priority_queue<int,vector<int>, greater<int> > pq;
        for(int i=0;i<r;i++){
            sort(grid[i].begin(),grid[i].end(),greater());
            for(int j=0;j<limits[i];j++ ){
                if(pq.size()==k){
                    if(pq.top()<grid[i][j]){
                        pq.pop();
                        pq.emplace(grid[i][j]);
                    } 
                }
                else pq.emplace(grid[i][j]);
            } 
        }

        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        } 

        return sum;
    }
};