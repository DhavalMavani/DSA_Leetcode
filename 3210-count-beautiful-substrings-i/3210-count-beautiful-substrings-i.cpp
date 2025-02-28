class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int vowelCount=0;
            for(int j=i;j<n;j++){
                char ch=s[j];
                if( ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u' ) vowelCount++;
                if((2*vowelCount)==j-i+1 && (vowelCount*vowelCount)%k==0) ans++;
            }
        }

        return ans;
    }
};