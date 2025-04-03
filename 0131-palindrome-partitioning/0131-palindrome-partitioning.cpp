class Solution {
private:
    void generatepartition(int curr,vector<string> res,vector<vector<bool>> &dp,string &s){
        int n=s.size();
        if(curr==n){
            ans.emplace_back(res);
            return;
        }

        for(int i=curr;i<n;i++){
            if(dp[curr][i] ){
                res.emplace_back(s.substr(curr,i-curr+1));
                generatepartition(i+1,res,dp,s);
                res.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string &s) {
        int n=s.size();

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=true;

        for(int len=3;len<=n;len++){
            for(int endPos=len-1;endPos<n;endPos++){
                int strPos=endPos-len+1;
                if(s[strPos]==s[endPos] && dp[strPos+1][endPos-1] ){
                    dp[strPos][endPos]=true;
                }
            }
        }

        generatepartition(0,{},dp,s);

        return ans;
    }
};