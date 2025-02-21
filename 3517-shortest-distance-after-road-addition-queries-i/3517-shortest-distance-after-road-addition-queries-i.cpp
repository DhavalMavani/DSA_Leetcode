class Solution {
public:
    void updateDistanceDfs(int node,vector<vector<int>> &adj,vector<int> &dist){
        for(auto &i: adj[node]){
            if(dist[i]<=1+dist[node]) continue;
            dist[i]= 1+ dist[node];
            updateDistanceDfs(i, adj, dist);
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dist(n);
        dist[0]=n-1;
        for(int i=1;i<n;i++){
            dist[i]=n-i-1;
            adj[i].emplace_back(i-1);
        } 
        
        int s=queries.size();
        vector<int> ans(s);

        for(int i=0;i<s;i++){
            int n1=queries[i][0], n2=queries[i][1];
            adj[n2].emplace_back(n1);

            updateDistanceDfs(n2,adj,dist);
            ans[i]=dist[0];
        }
        return ans;
    }
};