class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(auto &i: s) freq[i-'a']++;
        int oddChar=-1;
        string ans;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) oddChar=i;

            ans+=string(freq[i]/2, 'a'+i);
            freq[i]-= freq[i]/2;
        }

        if(oddChar!=-1){
            ans+='a'+oddChar;
            freq[oddChar]--;
        }

        for(int i=25;i>=0;i--) ans+=string(freq[i], 'a'+i);

        return ans;
    }
};