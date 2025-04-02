class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), ansStr=0, ansLen=1;
        vector<vector<bool>> dp(n,vector <bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                ansStr=i;
                ansLen=2;
                dp[i][i+1]=true;
            }
        }

        for(int len= 3; len<=s.size(); len++){
            for(int strPos=0;strPos<=s.size()-len;strPos++){
                int endPos=len+strPos-1;

                if(s[strPos]==s[endPos] && dp[strPos+1][endPos-1]){
                    dp[strPos][endPos]=true;
                    ansStr=strPos;
                    ansLen=len;
                } 
            }
        }
        return s.substr(ansStr,ansLen);
    }
};