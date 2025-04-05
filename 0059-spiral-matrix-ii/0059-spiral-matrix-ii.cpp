class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n,-1));
        int cnt=1;
        int lv=0,rv=n-1, th=0, bh=n-1;
        while(cnt<=n*n){
            for(int i=lv;i<=rv;i++) arr[th][i]=cnt++;
            th++;

            for(int i=th;i<=bh;i++) arr[i][rv]=cnt++;
            rv--;

            for(int i=rv;i>=lv;i--) arr[bh][i]=cnt++;
            bh--;

            for(int i=bh;i>=th;i--) arr[i][lv]=cnt++;
            lv++;

        }
        return arr;
    }
};
