class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long ans=0;
        int n=nums.size(), prefixSum=0;
        unordered_map<int,int> ump;
        ump[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%m==k) prefixSum++;

            int r1=prefixSum % m , r2=(r1-k+m)%m;

            if(ump.count(r2)) ans+=ump[r2];
            ump[r1]++;
        }

        return ans;
    }
};