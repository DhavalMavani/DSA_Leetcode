class Solution {
public:
    long long calcSum(long long n){
        return  (n*(n+1))/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=0, count=0;
        int n=nums.size();
        if(nums[0]>1){
            if(nums[0]-1 < k){
                ans+=calcSum(nums[0]-1);
                count+=nums[0]-1;
            }
            else return calcSum(k);
        }
        for(int i=1;i<n &&  count < k ;i++){
            int diff=nums[i]-nums[i-1]-1;
            if(diff>0){
                if(count+diff<=k){
                    ans+=calcSum(nums[i]-1)- calcSum(nums[i-1]);
                    count+=diff;
                }
                else return ans+=  calcSum(nums[i-1]+k-count ) -calcSum(nums[i-1]);
            }
        }
        if(count<k) ans+=calcSum(nums[n-1]+k-count ) -calcSum(nums[n-1]);
        return ans;
    }
};