class Solution {
public:
    void helper(vector<vector<int>> &ans,int k,int n,int curr,vector<int> res){
        if(k==0){
            if(n==0) ans.emplace_back(res);
            return;
        }

        for(int i=curr;i<=9;i++){
            res.emplace_back(i);
            if(n-i>=0) helper(ans,k-1,n-i,i+1,res);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(ans,k,n,1,{});
        return ans;
    }
};