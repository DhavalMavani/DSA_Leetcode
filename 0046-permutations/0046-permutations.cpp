class Solution {
private:
    void generate_permutation(vector<int> &nums,int curr){
        if(curr==n){
            ans.emplace_back(nums);
            return;
        }
        for(int i=curr;i<n;i++){
            swap(nums[curr],nums[i]);
            generate_permutation(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
public:
    vector<vector<int>> ans;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        generate_permutation(nums,0);
        return ans;
    }
};