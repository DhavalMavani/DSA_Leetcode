class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set <int> ust;

        for(int i=0;i<nums.size();i++){
            if ( !ust.count(nums[i]) ) ust.emplace(nums[i]);
            else return true;
        }
        return false;
    }
};