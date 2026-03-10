class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,ans=0;
        unordered_map<int,int> ump;
        ump[0]=1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(ump.count(sum-k)) ans+=ump[sum-k];
            ump[sum]++;
        }
        return ans;
    }
};