class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k=queries.size(), m=grid.size(), n=grid[0].size(), ind=0,count=0;
        vector<int> ans(k);
        vector<pair<int,int>> arr;
        for(int i=0;i<k;i++) arr.push_back({queries[i],i});
        sort(arr.begin(),arr.end());


        vector<bool> vis(m*n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;

        q.push({grid[0][0],0});
        vis[0]=true;

        int dirs[5]={0,1,0,-1,0};
        
        while(!q.empty() && ind<k){
            auto [val, pos] = q.top();
            q.pop();
            while(ind<k && val>=arr[ind].first){
                ans [arr[ind].second] =count;
                ind++;
            }

            count++;
            for(int i=0;i<4;i++){
                int x=dirs[i], y=dirs[i+1], r= pos/n, c= pos%n, newPos=(r+x)*n +c+y;
                if(r+x>=0 && r+x<m && c+y>=0 && c+y<n && !vis[newPos] ){
                    vis[newPos ]=true;
                    q.push({grid[r+x][c+y],newPos });
                }
            }
        }

        while (ind < k) {
            ans[arr[ind].second]=count;
            ind++;
        }
        return ans;
    }
};