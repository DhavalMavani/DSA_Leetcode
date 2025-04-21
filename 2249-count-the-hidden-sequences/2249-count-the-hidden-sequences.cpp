class Solution {
public:
    int numberOfArrays(vector<int>& differences, long long lower, long long upper) {
        int n=differences.size(), mini=0, maxi=0,prefix=0;

        for(int i=0;i<n;i++){
            prefix+=(long long) differences[i];
            mini=min(mini, prefix);
            maxi=max(maxi, prefix);
        }

        lower-=(long long)mini;
        upper-=(long long)maxi;
        
        if(lower>upper) return 0;
        
        return (long long)upper-lower+1;
    }
};