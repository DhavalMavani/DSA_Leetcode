class Solution {
public:
    int helper(int currInd,vector<int>& arr, int &d, vector<int> &dp){
        int count=0, maxH=arr[currInd];
        
        if(dp[currInd]!=-1) return dp[currInd];
        int lim=min((int) arr.size()-1,currInd+d);
        for(int i=currInd+1; i<=lim ;i++ ){
            if(arr[i]>=arr[currInd]) break;
            count=max(count,helper(i,arr,d,dp) );
        }
        lim=max(0,currInd-d);
        for(int i=currInd-1; i>= lim;i-- ){
            if(arr[i]>=arr[currInd]) break;
            count=max(count,helper(i,arr,d,dp) );
        }

        return dp[currInd]=1 + count;
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(),-1);

        int ans=1;
        for(int i=0;i<arr.size();i++){
            ans=max(ans, helper(i,arr,d,dp) );
        }
        return ans;
    }
};