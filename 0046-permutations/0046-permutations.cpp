class Solution {
private:
    void generate_permutation(vector<int> &nums,int curr){
        if(curr==nums.size()){
            ans.emplace_back(nums);
            return;
        }
        for(int i=curr;i<nums.size();i++){
            swap(nums[curr],nums[i]);
            generate_permutation(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        generate_permutation(nums,0);
        return ans;
    }
};