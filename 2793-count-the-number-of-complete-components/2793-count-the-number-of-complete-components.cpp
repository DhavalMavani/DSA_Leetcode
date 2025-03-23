class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> count;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        count.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int a){
        if(parent[a]==a) return a;
        return parent[a]= findParent(parent[a]);
    }

    void merge(int a,int b){
        int pa=findParent(a);
        int pb=findParent(b);
        if(pa==pb){
            count[pa]++;
            return;
        }
        if(rank[pa]>=rank[pb]){
            parent[pb]=pa;
            rank[pa]+=rank[pb];
            count[pa]+=count[pb]+1;
        }
        else{
            parent[pa]=pb;
            rank[pb]+=rank[pa];
            count[pb]+=count[pa]+1;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        DSU* dsu=new DSU(n);
        for(auto &i: edges){
            dsu->merge(i[0],i[1]);
        }

        unordered_set<int> ust;
        for(int i=0;i<n;i++) ust.emplace(dsu->findParent(i));

        for(auto &i: ust){
            int s=dsu->rank[i]-1, count=dsu->count[i];
            if(count== ((s*(s+1))/2)) ans++;
        }

        return ans;
    }
};

// n-1 + n-2 + n-3
// 2, 1
// n(n+1)/2