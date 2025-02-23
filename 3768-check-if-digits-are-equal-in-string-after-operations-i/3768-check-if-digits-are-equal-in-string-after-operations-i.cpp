class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            int n=s.size();
            string s2;
            for(int i=1;i<n; i++) s2+= to_string ( (s[i]-'0' + s[i-1]-'0')%10 ) ;
            if(s2.size()==2 ) return s2[0]==s2[1];
            s=s2;
        }
        return false;
    }
};

