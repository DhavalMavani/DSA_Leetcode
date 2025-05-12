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
    vector<TreeNode*> helper(int n, vector<vector<TreeNode*>> &dp){

        if(! dp[n].empty() ) return dp[n];
        
        vector<TreeNode*> ans;
        for(int left=1;left<=n-2;left+=2){
            int right=n-1-left;

            vector<TreeNode*> leftTree=helper(left,dp);
            vector<TreeNode*> rightTree=helper(right,dp);

            for(auto &l: leftTree){
                for(auto &r: rightTree){
                    TreeNode* curr=new TreeNode();
                    curr->left=l;
                    curr->right=r;
                    ans.emplace_back(curr);
                }
            }
        }

        if(ans.empty()) return dp[n]={new TreeNode() };
        return dp[n]=ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};

        vector<vector<TreeNode*>> dp(n+1);

        return helper(n,dp);
    }
};