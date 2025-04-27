class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size(),minKInd=-1,maxKInd=-1,culpritIndex=-1;
        long long ans=0;

        for(int i=0;i<n;i++){
            int num=nums[i];

            if(num==minK) minKInd=i;
            if(num==maxK) maxKInd=i;
            else if(num<minK || num>maxK) culpritIndex=i;

            if(min(minKInd,maxKInd)-culpritIndex>0 ) ans+=min(minKInd,maxKInd)-culpritIndex;
        }

        return ans;
    }
};