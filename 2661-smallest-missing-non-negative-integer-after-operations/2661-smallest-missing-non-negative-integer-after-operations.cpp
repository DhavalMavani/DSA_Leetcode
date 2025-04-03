class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> arr(value,0);
        int n=nums.size(),mini=INT_MAX, miniInd=INT_MAX;

        for(auto &i: nums){
            // cout<<i%value<<" ";
            int t=i%value;
            if(t<0) t+=value;
            arr[t]++;
        } 
        // cout<<"\n\n";

        for(int i=0;i<value;i++){
            if(arr[i]==0) return i;
            if(arr[i]<mini){
                miniInd=i;
                mini=arr[i];
            }
        }
        return mini*value+miniInd;

    }
};