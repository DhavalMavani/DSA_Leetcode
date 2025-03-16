class Solution {
public:

    bool check(vector<int>& ranks, int cars, long long &t){
        for(auto &r: ranks){
            cars-= int ( sqrt(t/r) );
            if(cars<=0) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1,r=INT_MIN;
        for(auto &i: ranks) r=max((long long)i,r);

        r*= ((long long)cars*cars);
        

        while(l<=r){
            long long mid=(l+r)/2;

            if(check(ranks, cars, mid) ){
                r=mid-1;
            }
            else l=mid+1;
        }

        return l;
    }
};