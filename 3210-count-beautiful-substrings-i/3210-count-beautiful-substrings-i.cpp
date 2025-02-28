class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.size(),ans=0;
        unordered_set<char> vowel;
        vowel.emplace('a');
        vowel.emplace('e');
        vowel.emplace('i');
        vowel.emplace('o');
        vowel.emplace('u');
        for(int i=0;i<n;i++){
            int vowelCount=0;
            for(int j=i;j<n;j++){
                if(vowel.count( s[j] ) ) vowelCount++;
                if((2*vowelCount)==j-i+1 && (vowelCount*vowelCount)%k==0) ans++;
            }
        }

        return ans;
    }
};