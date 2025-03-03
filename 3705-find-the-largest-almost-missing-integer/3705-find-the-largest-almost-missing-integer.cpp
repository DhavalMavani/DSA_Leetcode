class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(), nums.end());
        else if(k==1){
            vector<int> freq(51,0);
            for(auto &i: nums) freq[i]++;
            for(int i=50;i>=0;i--) if(freq[i]==1) return i;
            return -1;
        }

        int f=nums[0], l=nums[nums.size()-1], cf=0,cl=0;
        if(f==l) return -1;
        for(auto &i: nums){
            if(i==f) cf++;
            else if(i==l) cl++;
        }

        if(cf!=1 && cl!=1) return -1;
        else if(cf==1 && cl==1) return max(l,f);
        else if(cf==1) return f;
        else return l;

        return 0;
    }
};