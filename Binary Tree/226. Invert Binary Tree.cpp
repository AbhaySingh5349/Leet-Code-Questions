class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        
        TreeNode* nl=invertTree(root->left);
        TreeNode* nr=invertTree(root->right);
        
        root->left=nr;
        root->right=nl;
        
        return root;
    }
};
