class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(auto &i: s) freq[i-'a']++;

        int l=0,n=s.size();
        string ans(n,'*');
        
        if(n%2) ans[n/2]=s[n/2];

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            for(int j=0;j<freq[i]/2;j++,l++){
                ans[l]='a'+i;
                ans[n-1-l]='a'+i;
            }
        }


        return ans;
    }
};