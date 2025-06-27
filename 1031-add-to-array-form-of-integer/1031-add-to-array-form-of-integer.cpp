class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int rem=0;

        for(int i=num.size()-1;i>=0 || k;i--){
            int temp=rem+k%10;
            if(i>=0) temp+=num[i];
            ans.emplace_back(temp%10);
            rem=temp/10;
            k/=10;
        }
        if(rem) ans.emplace_back(rem);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};