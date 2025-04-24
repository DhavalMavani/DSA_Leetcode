class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(auto &i: nums) ump[i]++;
        int s=ump.size(), ans=0,l=0,r=0,n=nums.size();

        ump.clear();
        while(l<n){

            while(r<n && ump.size()!=s){
                ump[nums[r]]++;
                r++;
            }
            if(ump.size()!=s) return ans;
            ans+= n-r+1;
            ump[nums[l]]--;
            if(ump[nums[l]]==0) ump.erase(nums[l]);
            l++;
        }

        return ans;
    }
};