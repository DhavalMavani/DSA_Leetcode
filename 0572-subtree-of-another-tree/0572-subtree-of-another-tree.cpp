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
private:
    bool isSame(TreeNode* &p,TreeNode* &q){
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL || p->val!=q->val) return false;

        bool a=isSame(p->left,q->left);
        bool b=isSame(p->right,q->right);

        return a && b;
    }    
public:
    bool isSubtree(TreeNode* &root, TreeNode* &subRoot) {
        if (root==NULL) return false;
        if(isSame(root,subRoot)) return true;

        return isSubtree( root->left, subRoot) || isSubtree( root->right, subRoot);
    }
};