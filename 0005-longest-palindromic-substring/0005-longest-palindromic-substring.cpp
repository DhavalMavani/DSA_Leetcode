class Solution {
private:
    bool palindrome(string &s,int &strPos,int &endPos,vector<vector<bool>> &dp){
        if( s[strPos]==s[endPos] && dp[strPos+1][endPos-1] ){
            return dp[strPos][endPos]=true;
        }
        return false;
    }
public:
    string longestPalindrome(string s) {
        string ansStr=s.substr(0,1);
        int n=s.size();
        vector<vector<bool>> dp(n,vector <bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                ansStr=s.substr(i,2);
            }
        }

        for(int len= 3; len<=s.size(); len++){
            for(int strPos=0;strPos<=s.size()-len;strPos++){
                int endPos=len+strPos-1;
                bool a=palindrome(s,strPos,endPos,dp);

                if(a && len>ansStr.size()) ansStr=s.substr(strPos,len);
            }
        }
        return ansStr;
    }
};