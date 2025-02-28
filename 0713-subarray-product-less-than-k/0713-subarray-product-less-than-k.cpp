class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,n=nums.size();

        for(int i=0;i<n;i++){
            int product=1, j=i;

            while(j<n && product*nums[j]< k){
                product*=nums[j];
                j++;
                ans++;
            }
        }
        return ans;
    }
};