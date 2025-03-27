class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominatrix,n=nums.size(),count=0;
        if(n==1) return -1;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++) freq[nums[i]]++;

        for(auto &i: freq){
            if(i.second>count){
                count=i.second;
                dominatrix=i.first;
            } 
        }
        
        int left=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==dominatrix) left++;
            if( (left> (i+1)/2) && ( count-left >(n -i-1)/2  ) ) return i;
        }
        return -1;   
    }
};