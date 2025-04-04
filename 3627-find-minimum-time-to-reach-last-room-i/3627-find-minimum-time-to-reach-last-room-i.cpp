class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int r=moveTime.size(),c=moveTime[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,0});
        vis[0][0]=1;
        int dirs[]={0,1,0,-1,0};

        while(!pq.empty()){
            auto [time,cell]=pq.top();
            pq.pop();
            if(cell==r*c-1) return time;
            int x=cell/c,y=cell%c;
            for(int i=0;i<4;i++){
                int a=x+dirs[i],b=y+dirs[i+1];
                if(a>=0 && b>=0 && a<r && b<c && !vis[a][b]){
                    vis[a][b]=true;
                    pq.push({1+max(time,moveTime[a][b]),a*c+b});
                }
            }

        }
        return 0;
    }
};