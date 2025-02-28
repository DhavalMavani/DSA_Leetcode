class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int vowel=0, consonant=0;
            for(int j=i;j<n;j++){
                if( s[j]=='a'|| s[j]=='e'|| s[j]=='i'|| s[j]=='o'|| s[j]=='u' ) vowel++;
                else consonant++;

                if(vowel==consonant && (vowel*vowel)%k==0) ans++;
            }
        }
        return ans;
    }
};