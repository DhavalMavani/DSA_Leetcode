class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(auto &i: s) freq[i-'a']++;

        int l=0,n=s.size();
        string ans(n,'*');

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            cout<<char('a'+i)<<" "<<freq[i]<<" \n";
            for(int j=0;j<freq[i]/2;j++,l++){
                ans[l]='a'+i;
                ans[n-1-l]='a'+i;
            }
            if(freq[i]%2) ans[n/2]='a'+i;
        }


        return ans;
    }
};