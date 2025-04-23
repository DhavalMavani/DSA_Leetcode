class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> arr(37,0);

        for(int i=1;i<=n;i++){
            int curr=i, currSum=0;

            while(curr){
                currSum+=curr%10;
                curr/=10;
            }
            arr[currSum]++;
        }
        
        int largestGroup=0,ans=0;
        for(auto &i: arr) largestGroup=max(largestGroup,i);
        for(auto &i: arr) if(i==largestGroup) ans++;

        return ans;

    }
};