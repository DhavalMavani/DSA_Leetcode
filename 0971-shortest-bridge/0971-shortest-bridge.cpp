class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c,queue<pair<int,int>> &q){
        if(r>=grid.size() || c>=grid.size() || r<0 || c<0 || grid[r][c]!=1) return;
        grid[r][c]=2;
        q.push({r,c});
        dfs(grid,r+1,c,q);
        dfs(grid,r-1,c,q);
        dfs(grid,r,c+1,q);
        dfs(grid,r,c-1,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        int offset[]={0,1,0,-1,0};
        int dist=3;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0;i<qs;i++){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int r=x+offset[j],c=y+offset[j+1];
                    if(r>=grid.size() || c>=grid.size() || r<0 || c<0 || (grid[r][c]<=dist && grid[r][c]>1) ) continue;
                    if(grid[r][c]==1) return dist-3;
                    grid[r][c]=dist;
                    q.push({r,c});
                }
            }
            dist++;
        }

        return dist-3;
    }
};
