class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size(), maxi=INT_MIN,ans=0;
        for(int i=0;i<n;i++) {
            if(nums[i]>=maxi){
                maxi=nums[i];
                ans++;
            }
        }
        return ans;
    }
};