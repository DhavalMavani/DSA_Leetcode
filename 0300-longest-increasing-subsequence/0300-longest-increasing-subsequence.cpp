class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            auto itr= lower_bound(sorted.begin(),sorted.end(),curr);

            if(itr==sorted.end()) sorted.emplace_back(nums[i]);
            else *itr=nums[i];
        }
        return sorted.size();
    }
};