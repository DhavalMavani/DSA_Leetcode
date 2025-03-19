class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0, usedBits=0, l=0;
        for(int r=0;r<nums.size();r++){

            while( (usedBits & nums[r]) !=0  ){
                usedBits ^= nums[l];
                l++;
            }

            usedBits |= nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;

    }
};