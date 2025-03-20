
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> ans;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        ans.resize(n,INT_MAX);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUltimateParent(int &a){
        if(parent[a]==a) return a;
        return parent[a]=findUltimateParent(parent[a]);
    }
    void merge(int &a,int &b, int &dist){
        int parentOfA=findUltimateParent(a);
        int parentOfB=findUltimateParent(b);

        if(rank[a]>=rank[b]){
            parent[parentOfB]=parentOfA;
            ans[parentOfA]=ans[parentOfA] & ans[parentOfB] & dist;
            rank[parentOfA]++;
        }
        else{
            parent[parentOfA]=parentOfB;
            ans[parentOfB]=ans[parentOfA] & ans[parentOfB] & dist;
            rank[parentOfB]++;
        }
    }

};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU* dsuPointer= new DSU(n);
        
        for(auto &i: edges) dsuPointer->merge(i[0],i[1],i[2]);

        vector<int> ans;
        for(auto &i: query){
            int parent_1=dsuPointer->findUltimateParent(i[0]);
            int parent_2=dsuPointer->findUltimateParent(i[1]);
            if(parent_1==parent_2)ans.emplace_back(dsuPointer->ans[parent_1]);
            else ans.emplace_back(-1);
        }

        return ans;
    }
};