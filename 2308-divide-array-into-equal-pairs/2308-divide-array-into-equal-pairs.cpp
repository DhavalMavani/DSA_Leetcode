class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> hash(501);
        for(auto &i: nums) hash[i]++;
        for(auto &i: hash) if(i%2) return false;
        return true;
    }
};