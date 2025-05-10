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
    vector<TreeNode*> generateBST(int l,int r){
        if(l>r ) return {NULL};
        if(l==r){
            return {new TreeNode(l)};
        }

        vector<TreeNode*> ans;

        for(int i=l;i<=r;i++){

            vector<TreeNode*> leftTree=generateBST(l,i-1);
            vector<TreeNode*> rightTree=generateBST(i+1,r);
            for(auto &left: leftTree){
                for(auto &right: rightTree){
                    TreeNode* curr=new TreeNode(i);
                    curr->left=left;
                    curr->right=right;
                    ans.emplace_back(curr);
                }
            }
        }
        return ans;   
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateBST(1,n);
    }
};