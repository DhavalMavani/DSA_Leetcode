class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> ust;
        for(auto &i: nums){
            if(ust.count(i) ) ust.erase(i);
            else ust.emplace(i);
        }
        return ust.empty();
    }
};