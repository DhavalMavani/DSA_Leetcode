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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;

        q.emplace(root);

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n-1;i++){
                TreeNode* currNode=q.front();
                q.pop();

                if(currNode->left) q.emplace(currNode->left);
                if(currNode->right) q.emplace(currNode->right);
            }
            TreeNode* currNode=q.front();
            q.pop();
            ans.emplace_back(currNode->val);
            if(currNode->left) q.emplace(currNode->left);
            if(currNode->right) q.emplace(currNode->right);
        }
        
        return ans;
        
    }
};