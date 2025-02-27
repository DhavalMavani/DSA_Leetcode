class Solution {
public:
    bool dfs(int node, int parent,int time,vector<vector<int>> &adj,vector<int> &bobTime){
        if(node==0) return true;

        for(auto &i: adj[node]){
            if(i==parent) continue;

            if ( dfs(i,node,time+1,adj,bobTime) ){
                bobTime[node]=time;
                return true;
            }
        }
        return false;
    }

    int aliceDfs(int node, int parent,int time,vector<int>& bobTime,vector<vector<int>> &adj,vector<int>& amount){

        int price=INT_MIN;

        for(auto &i: adj[node]){
            if(i==parent) continue;
            price=max(price, aliceDfs(i,node,time+1,bobTime,adj,amount));
        }
        if(price==INT_MIN) price=0;
        
        if(time<bobTime[node] ) price+=amount[node];
        else if(time==bobTime[node]) price+= (amount[node]/2);

        return price;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int e=edges.size();
        vector<vector<int>> adj (e+1);

        for(auto &edge: edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> bobTime(e+1,1e9);
        dfs(bob,-1, 0, adj,bobTime);

        return aliceDfs(0,-1,0,bobTime,adj, amount);

    }
};