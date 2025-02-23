class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            int n=s.size();
            string s2;
            for(int i=1;i<n; i++) s2+= to_string ( (s[i]-'0' + s[i-1]-'0')%10 ) ;
            s=s2;
        }
        return s[0]==s[1];
    }
};

