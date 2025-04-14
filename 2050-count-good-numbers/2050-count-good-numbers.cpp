class Solution {
public:
    int mod=1e9 + 7;
    long long calc(int base,long long n){
        if(n==0) return 1;
        if(n==1) return base;
        
        long long ans=calc(base,n/2)%mod;
        
        if(n%2) return (ans*ans*base)%mod;

        return (ans*ans)%mod;
    }
    int countGoodNumbers(long long n) {
        if(n%2) return (calc(5,n/2+1)*calc(4,n/2))%mod;
        return (calc(5,n/2)*calc(4,n/2))%mod;
    }
};