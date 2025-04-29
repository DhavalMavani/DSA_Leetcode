class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum=*max_element(nums.begin(),nums.end());
        int freq=0,l=0,n=nums.size();
        long long ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxNum) freq++;

            if(freq==k){
                while(freq>=k){
                    ans+=n-i;
                    if(maxNum==nums[l]) freq--;
                    l++;
                }
            }
        }
        return ans;
    }
};