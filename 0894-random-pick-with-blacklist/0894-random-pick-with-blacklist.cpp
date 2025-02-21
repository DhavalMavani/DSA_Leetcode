class Solution {
public:

    int approach;

    int n, m;

    unordered_set<int> hash_set;

    vector<int> whitelist;


    Solution(int nn, vector<int>& blacklist) {
        n = nn;
        m = blacklist.size();
        for(auto it : blacklist) hash_set.insert(it);
        if(m * 2 < n) approach = 1;
        else {
            approach = 2;
            for(int i = 0; i < n; i++) {
                if(hash_set.find(i) == hash_set.end()) {
                    whitelist.push_back(i);
                }
            }
        }
    }
    
    int pick() {
        if(approach == 1) {
            while(true) {
                int val = rand() % n;
                if(!hash_set.count(val) )  return val;
            }
        }
        else {
            int idx = rand() % whitelist.size();
            return whitelist[idx];
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */