class Solution {
public:
    vector<int> nums;
    int s;
    Solution(int n, vector<int>& blacklist) {
        n=min((int)1e6,n);
        unordered_set<int> ust(begin(blacklist), end(blacklist));
        for(int i=0;i<n;i++) if(!ust.count(i)) nums.emplace_back(i);
        ust.clear();
        s=nums.size();
    }
    
    int pick() {
        return nums[rand()%s];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */