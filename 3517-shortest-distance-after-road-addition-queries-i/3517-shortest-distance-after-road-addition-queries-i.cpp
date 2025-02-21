class Solution {
public:
    int bfs(vector<vector<int>> &adj){
        int dist=0;
        queue<int> q;
        q.emplace(0);
        
        vector<bool> vis(adj.size(),false);
        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){

                int curr=q.front();
                q.pop();
                vis[curr]=true;
                if(curr==adj.size()) return dist;

                for(auto &node: adj[curr] ){
                    if(!vis[node]) q.emplace(node);
                }
            }
            dist++;

        }
        return dist;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n-1);
        for(int i=0;i<n-1;i++) adj[i].emplace_back(i+1);
        
        int s=queries.size();
        vector<int> ans(s);
        for(int i=0;i<s;i++){
            int n1=queries[i][0], n2=queries[i][1];
            adj[n1].emplace_back(n2);

            ans[i]=bfs(adj);
        }
        return ans;
    }
};