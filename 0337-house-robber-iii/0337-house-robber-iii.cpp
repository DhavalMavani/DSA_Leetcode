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
    // {take, notTake}
    pair<int,int> helper(TreeNode* node){
        if(node==NULL) return {0,0};

        auto l=helper(node->left);
        auto r=helper(node->right);

        return {node->val+l.second+r.second, max(l.first,l.second)+max(r.first,r.second)};
    }
    int rob(TreeNode* root) {
        auto ans=helper(root);
        return max(ans.first,ans.second);
    }
};