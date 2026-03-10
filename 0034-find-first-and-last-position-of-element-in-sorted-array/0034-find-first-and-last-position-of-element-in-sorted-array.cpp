class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos={-1,-1};
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]>=target) r=mid-1;
            else l=mid+1;
        }
        if(l>=0 && l<nums.size() && nums[l]==target)pos[0]=l;
        else return pos;

        l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<=target) l=mid+1;
            else r=mid-1;
        }
        if(r>=0 && r<nums.size()) pos[1]=r;
        
        return pos;
    }
};