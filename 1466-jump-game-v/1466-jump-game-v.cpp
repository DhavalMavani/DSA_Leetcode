class Solution {
public:
    int helper(int currInd,vector<int>& arr, int &d, vector<int> &dp){
        int count=0, maxH=arr[currInd],n=arr.size();
        
        if(dp[currInd]!=-1) return dp[currInd];

        int lim=min((int) n-1,currInd+d);
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
        int n=arr.size(), ans=1;

        vector<int> dp(n,-1);

        for(int i=0;i<n;i++) ans=max(ans, helper(i,arr,d,dp) );

        return ans;
    }
};