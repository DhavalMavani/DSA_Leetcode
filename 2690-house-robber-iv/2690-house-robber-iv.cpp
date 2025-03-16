class Solution {
public:
    bool check(vector<int>& nums, int k,int index, int &val) {
        if(k==0) return true;
        if(index>=nums.size()) return false;
        
        if(nums[index]<=val) return check(nums,k-1,index+2,val);
        
        return check(nums,k,index+1,val);
    }
    int minCapability(vector<int>& nums, int k) {
        int l=INT_MAX,r=INT_MIN;
        for(auto &i: nums){
            l=min(i,l);
            r=max(i,r);
        }

        while(l<=r){
            int mid=(l+(r-l)/2);
            if( check(nums,k,0,mid) ) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};