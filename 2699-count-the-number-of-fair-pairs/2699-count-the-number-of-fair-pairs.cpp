class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0; 

        for(int i=0;i<n-1;i++){
            int l=i+1,r=n-1,     lim1=lower-nums[i], lim2=upper-nums[i];
            
            int a=lower_bound(nums.begin()+l, nums.begin()+r+1, lim1)-nums.begin();
            int b=upper_bound(nums.begin()+l, nums.begin()+r+1, lim2)-nums.begin()-1;

            if(b>=a) ans+=b-a+1;
        }

        return ans;
    }
};