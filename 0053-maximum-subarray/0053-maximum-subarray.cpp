class Solution {
private: 

public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,right=0, sum=0;
        while(right!=nums.size()){
            sum+=nums[right];
            ans=max(sum,ans);
            if(sum<0) sum=0;
            right++;
        }
        return ans;
    }
};