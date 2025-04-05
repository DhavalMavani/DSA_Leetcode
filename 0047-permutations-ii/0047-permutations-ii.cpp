class Solution {

private:
    void generate_permutation(vector<int> &nums,int curr){
        if(curr==nums.size()-1){
            ans.emplace_back(nums);
            return;
        }
        unordered_set<int> ust;
        for(int i=curr;i<nums.size();i++){
            if(ust.count(nums[i])) continue;
            
            ust.emplace(nums[i]);

            swap(nums[curr],nums[i]);
            generate_permutation(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        generate_permutation(nums,0);
        return ans;
    }
};