class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum = 0;
        
        unordered_map<int,int> ump;
        ump[0]=-1;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int curr = sum%k;

            if (ump.count(curr) ){
                if(i-ump[curr]>=2) return true;
            } 
            else  ump[curr]=i;
        }
        return false;
    }
};
