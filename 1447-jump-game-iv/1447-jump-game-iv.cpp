class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()<3) return arr.size()-1;

        int n=arr.size(),steps=0;
        
        unordered_map<int,vector<int> > ump;
        for(int i=0;i<n;i++) ump[arr[i]].emplace_back(i);
        
        vector<bool> vis(n,false);
        queue<int> q;
        q.emplace(0);
        vis[0]=true;
        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int currInd=q.front();
                q.pop();

                if(currInd==n-1) return steps;

                if(currInd>0 && !vis[currInd-1]){
                    q.emplace(currInd-1);
                    vis[currInd-1]=true;
                }
                if(currInd<n-1 && !vis[currInd+1]){
                    q.emplace(currInd+1);
                    vis[currInd+1]=true;
                }

                for(auto &ind: ump [ arr[currInd] ] ){
                    if(!vis[ind]){
                        q.emplace(ind);
                        vis[ind]=true;
                    }
                }
                ump[arr[currInd]].clear();  
            }
            steps++;
        }
        return steps;
    }
};