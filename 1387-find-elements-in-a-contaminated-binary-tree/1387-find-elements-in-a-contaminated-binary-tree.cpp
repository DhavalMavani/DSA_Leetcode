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
class FindElements {
public:
    unordered_set<int> ust;
    void solve(TreeNode* node){
        
        ust.emplace(node->val);
        if(node->left!=NULL){
            node->left->val=2*node->val+1;
            solve(node->left);
        } 

        if(node->right!=NULL){
            node->right->val=2*node->val+2;
            solve(node->right);
        } 
    }

    
    FindElements(TreeNode* root) { 
        root->val=0;
        solve(root);
    }

    
    bool find(int target) {
        return ust.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */