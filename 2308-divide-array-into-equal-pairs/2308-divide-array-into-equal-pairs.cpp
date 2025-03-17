class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto &i: nums) ump[i]++;

        for(auto &i: ump) if(i.second%2) return false;
        return true;
    }
};