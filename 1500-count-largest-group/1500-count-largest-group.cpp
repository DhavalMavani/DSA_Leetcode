class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> ump;
        int largestGroup=0,ans=0;
        for(int i=1;i<=n;i++){
            int curr=i, currSum=0;

            while(curr){
                currSum+=curr%10;
                curr/=10;
            }
            ump[currSum]++;
            largestGroup=max(largestGroup,ump[currSum]);
        }
        for(auto &i: ump) if(i.second==largestGroup) ans++;

        return ans;

    }
};