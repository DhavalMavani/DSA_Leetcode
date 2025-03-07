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

        vector<int> prime;
        for(int i=left;i<=right;i++) if(isPrime[i]) prime.emplace_back(i);

        if(prime.size()<2) return {-1,-1};

        vector<int> ans(2);
        ans[0]=prime[0];
        ans[1]=prime[1];

        int minDiff=prime[1]-prime[0];

        for(int i=2;i<prime.size();i++){
            if(minDiff > prime[i]-prime[i-1]){
                minDiff=prime[i]-prime[i-1];
                ans[0]=prime[i-1];
                ans[1]=prime[i];
            }
        }

        return ans;
    }
};