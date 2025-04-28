class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0,r=0,n=nums.size();
        long long ans=0, sum=0;

        while(r<=n){
            while(sum*(r-l)>=k){
                sum-=nums[l];
                l++;
            }
            ans+=r-l;

            if(r<n) sum+=nums[r];
            r++;
        }

        return ans;
    }
};