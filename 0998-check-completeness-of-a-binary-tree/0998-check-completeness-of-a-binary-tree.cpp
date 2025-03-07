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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.emplace(root);

        bool nullEncountered = false ;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(!nullEncountered && curr->left) q.emplace(curr->left);
                else if(nullEncountered && curr->left) return false;
                else nullEncountered=true;

                if(!nullEncountered && curr->right) q.emplace(curr->right);
                else if(nullEncountered && curr->right) return false;
                else nullEncountered=true;
            }
        }
        
        return true;
    }
};