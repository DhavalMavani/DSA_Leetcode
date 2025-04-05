class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0, l=0,r=0, n=nums.size();
        
        while(r<n-1){
            int temp=r;

            for(int i=l;i<=temp;i++) r=max(r,i+nums[i]);

            l=temp+1;
            ans++;
        }
        return ans;
    }
};