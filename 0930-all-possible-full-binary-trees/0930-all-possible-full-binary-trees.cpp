/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> helper(int n,vector<vector<TreeNode*>> &dp){
        if(n%2==0) return {};
        if(!dp[n].empty()) return dp[n];

        vector<TreeNode*> ans;
        for(int left=1;left<=n-1;left++){
            int right=n-1-left;
            vector<TreeNode*> leftArr=helper(left,dp);
            vector<TreeNode*> rightArr=helper(right,dp);

            for(auto i: leftArr){
                for(auto j: rightArr){
                    ans.emplace_back(new TreeNode(0,i,j));
                }
            }
        }

        return dp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        vector<vector<TreeNode*>> dp(n+1);
        dp[1]={new TreeNode()};
        return helper(n,dp);
    }
};