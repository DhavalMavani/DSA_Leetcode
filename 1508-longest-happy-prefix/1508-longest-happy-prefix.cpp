class Solution {
public:


    string longestPrefix(string s) {
        int len=0, n=s.size(),i=1;
        vector<int> LPS(n);
        LPS[0]=0;
        while(i<n){
            if(s[len]== s[i] ) LPS[i++]=++len;
            else{
                if(len!=0) len=LPS[len-1];
                else LPS[i++]=0;
            }
        }
        return s.substr( n-LPS[n-1],LPS[n-1]);
    }
};
