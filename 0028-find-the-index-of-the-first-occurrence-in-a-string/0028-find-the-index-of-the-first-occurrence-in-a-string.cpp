class Solution {
public:
    vector<int> calcLPS(string &s){
        int n=s.size(), len=0,i=1;
        vector<int> LPS(n);
        LPS[0]=0;

        while(i<n){
            if(s[i]== s[len]) LPS[i++]=++len;
            else{
                if(len!=0) len=LPS[len-1];
                else LPS[i++]=0;
            }
        }
        return LPS;
    }
    int strStr(string haystack, string needle) {
        
        vector<int> LPS= calcLPS(needle);
        int hs=haystack.size(),ns=needle.size(), i=0, j=0;

        while(i<hs && j<ns){
            if(haystack[i]==needle[j]) i++,j++;
            else{
                if(j!=0) j=LPS[j-1];
                else i++;
            }
        }

        return (j==ns)? i-j : -1;
    }
};