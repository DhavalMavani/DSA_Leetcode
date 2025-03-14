class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,ans=0,r = *max_element(candies.begin(), candies.end());

        while(l<=r){
            long long mid=(l+r)/2;
            long long temp=0;
            for(auto &i: candies){
                temp+=i/mid;
                if(temp>=k) break;
            }
            if(temp>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};