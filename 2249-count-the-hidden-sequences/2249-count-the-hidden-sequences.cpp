class Solution {
public:
    int numberOfArrays(vector<int>& differences, long long lower, long long upper) {
        int n=differences.size();
        for(int i=1;i<n;i++) differences[i]+=(long long) differences[i-1];

        long long mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini, (long long)differences[i]);
            maxi=max(maxi, (long long)differences[i]);
        }

        if(mini<0) lower-=(long long)mini;
        if(maxi>0) upper-=(long long)maxi;
        
        if((long long)upper-lower+1<0) return 0;
        
        return (long long)upper-lower+1;
    }
};