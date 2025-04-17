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
        string back=ans;
        reverse(back.begin(),back.end());
        if(oddChar!=-1){
            ans+='a'+oddChar;
            freq[oddChar]--;
        }

        return ans+back;
    }
};