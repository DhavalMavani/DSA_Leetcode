class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int s=right-left+1;

        vector<bool> isPrime(right+1,true);
        isPrime[1]=false;

        for(int i=2;i<=right;i++){
            if(isPrime[i] ){
                for(int j=2*i; j<=right; j+=i) isPrime[j]=false;
            }
        }
        int prev=-1, minDiff=1e9;
        vector<int> ans(2,-1);
        for(int i=left;i<=right;i++){
            if(isPrime[i]){
                if(prev==-1) prev=i;
                else{
                    if(ans[0]==-1 || minDiff > i-prev ){
                        ans[0]=prev;
                        ans[1]=i;
                        minDiff=i-prev;
                    }
                    prev=i;
                }
            } 
        }

        return ans;
    }
};