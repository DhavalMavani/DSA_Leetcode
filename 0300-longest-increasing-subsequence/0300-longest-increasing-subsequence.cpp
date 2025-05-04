class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            
            bool added=false;
            for(auto &j: ans){
                if(j>=curr){
                    j=curr;
                    added=true;
                    break;
                } 

            }
            if(!added) ans.emplace_back(curr);
        }
        return ans.size();
    }
};