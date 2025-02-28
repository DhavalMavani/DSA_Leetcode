class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,n=nums.size(), prod=1, l=0;
        if(k<=1) return 0;
        for(int r=0;r<n;r++){
            prod*=nums[r];

            while( prod>=k) prod/=nums[l], l++;
            
            ans+=r-l+1;
        }
        return ans;
    }
};