class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n=num.size(), i=n-1, rem=0;

        for(;i>=0 && k;i--){
            int temp=rem+num[i]+k%10;
            ans.emplace_back(temp%10);
            rem=temp/10;
            k/=10;
        }
        while(k){
            int temp= k%10 + rem;
            ans.emplace_back(temp%10);
            k/=10;
            rem=temp/10;
        }
        while(i>=0){
            int temp= num[i]+rem;
            ans.emplace_back(temp%10);
            rem=temp/10;
            i--;
        }
        if(rem) ans.emplace_back(rem);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};