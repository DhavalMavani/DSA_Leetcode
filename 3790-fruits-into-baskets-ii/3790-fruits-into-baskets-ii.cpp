class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(),ans=n;
        vector<bool> isUsed(n,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!isUsed[j] && baskets[j]>=fruits[i] ){
                    isUsed[j]=true;
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};