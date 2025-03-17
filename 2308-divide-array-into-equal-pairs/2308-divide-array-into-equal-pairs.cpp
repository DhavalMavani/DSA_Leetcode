class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> hash(501,false);
        for(auto &i: nums){
            if(hash[i]) hash[i]=0;
            else hash[i]=1;
        } 
        for(auto i: hash) if(i) return false;
        return true;
    }
};