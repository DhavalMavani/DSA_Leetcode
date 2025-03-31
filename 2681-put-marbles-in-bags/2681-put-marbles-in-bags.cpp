class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1) return 0;
        long long ans=0;
        int n=weights.size();
        vector<long long> arr;
        for(int i=0;i<n-1;i++) arr.emplace_back(weights[i]+weights[i+1]);

        sort(arr.begin(),arr.end());

        for(int i=0;i<k-1;i++) ans+= arr[n-2-i]-arr[i];

        return ans;
    }
};