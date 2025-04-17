class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int l=0,r=0,n=nums.size(), currPairs=0;
        unordered_map<int,int> ump;

        while(l<n){
            while(currPairs<k && r<n){
                currPairs+=ump[nums[r]];
                ump[nums[r]]++;
                r++;
            }

            if(currPairs>=k) ans+=n-r+1;
            else return ans;

            ump[nums[l]]--;
            currPairs-=ump[nums[l]];
            l++;
        }
        return ans;
    }
};