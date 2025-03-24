class Solution {
public:
    int longestEqualSubarray(vector<int>& s, int k) {

        int l=0,r=0,maxFrequency=0;
        unordered_map <int,int> ump;

        while(r<s.size()){
            ump[s[r]]++;
            maxFrequency=max(maxFrequency,ump[s[r]]);
            while((r-l+1)-maxFrequency>k){
                ump[s[l]]--;
                l++;
            }
            r++;
        };
        
        return maxFrequency;
    }
};