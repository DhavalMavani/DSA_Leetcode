class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> arr(3,LONG_MIN);

        for(auto &i: nums){
            if(i>arr[0]){
                arr[2]=arr[1];
                arr[1]=arr[0];
                arr[0]=i;
            }
            else if(i>arr[1]){
                if(i==arr[0]) continue;
                arr[2]=arr[1];
                arr[1]=i;
            }
            else if(i>arr[2]){
                if(i==arr[1]) continue;
                arr[2]=i;
            } 
        }

        if(arr[2]==LONG_MIN) return arr[0];
        return arr[2];
    }
};