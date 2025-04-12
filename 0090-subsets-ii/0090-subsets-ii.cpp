class Solution {
private:
    void generate_subset(vector<int> nums,vector<int> res,int curr){
        ans.emplace_back(res);
        for(int i=curr;i<nums.size();i++){
            if(i!=curr && nums[i]==nums[i-1]) continue;
            
            res.emplace_back(nums[i]);
            generate_subset(nums,res,i+1);
            res.pop_back();
        }
    }
    
public:
    vector <vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        generate_subset(nums,{},0);
        return ans;
    }
};