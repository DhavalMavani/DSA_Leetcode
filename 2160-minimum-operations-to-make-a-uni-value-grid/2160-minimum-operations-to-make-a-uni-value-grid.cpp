class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();
        if(m==1 && n==1) return 0;
        vector<int> arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.emplace_back(grid[i][j]);
            }
        }
        
        sort(arr.begin(),arr.end());
        int ans=INT_MAX,count=0, mid=(m*n)/2-1;
        for(auto &i: arr){
            if( (abs(arr[mid] - i))%x==0  ){
                count+= abs(arr[mid] - i)/x;
            }
            else{
                count=INT_MAX;
                break;
            } 
        }
        ans=min(ans,count);
        count=0;
        for(auto &i: arr){
            if( (abs(arr[mid] - i))%x==0  ){
                count+= abs(arr[mid+1] - i)/x;
            }
            else{
                count=INT_MAX;
                break;
            } 
        }
        ans=min(ans,count);

        return ans==INT_MAX ? -1: ans;
    }
};