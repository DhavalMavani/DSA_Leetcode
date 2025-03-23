class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs=haystack.size(),ns=needle.size(), i=1, j=0,len=0;
        
        vector<int> LPS(ns);
        LPS[0]=0;

        while(i<ns){
            if(needle[i]== needle[len]) LPS[i++]=++len;
            else{
                if(len!=0) len=LPS[len-1];
                else LPS[i++]=0;
            }
        }

        i=0;

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