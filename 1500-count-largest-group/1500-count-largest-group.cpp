class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> arr(37,0);

        int largestGroup=0,ans=0;
        for(int i=1;i<=n;i++){
            int curr=i, currSum=0;

            while(curr){
                currSum+=curr%10;
                curr/=10;
            }
            arr[currSum]++;
            largestGroup=max(largestGroup,arr[currSum]);
        }
        for(auto &i: arr) if(i==largestGroup) ans++;

        return ans;

    }
};