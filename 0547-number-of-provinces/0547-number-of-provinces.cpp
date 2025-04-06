class Solution {
private:
    int findUltimateParent(int node,vector <int> &parents){
        if(node==parents[node]) return node;

        parents[node]= findUltimateParent(parents[node],parents);
        return parents[node];
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector <int> parents(n);
        vector <int> rank(n,1);

        for(int i=0;i<n;i++) parents[i]=i;   

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    int a=findUltimateParent(i,parents);
                    int b=findUltimateParent(j,parents);

                    if(a==b) continue;
                    else if(rank[a]>=rank[b]){
                        rank[a]+=rank[b];
                        parents[b]=a;
                    }
                    else{
                        rank[b]+=rank[a];
                        parents[a]=b;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) findUltimateParent(i,parents);
        unordered_set <int> st(parents.begin(),parents.end());

        return st.size(); 
    }
};