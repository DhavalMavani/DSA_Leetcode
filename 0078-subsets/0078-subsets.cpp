class Solution {
public:

    void generateSubset(vector<int> nums,int curr,vector<int> &t1){
        if(curr==nums.size()){
            ans.emplace_back(t1);
            return;
        }
        generateSubset(nums,curr+1,t1);
        t1.emplace_back(nums[curr]);
        generateSubset(nums,curr+1,t1);
        t1.pop_back();
    }

    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t1;
        generateSubset(nums,0,t1);
        return ans;
    }
};