Question Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Approach 1:

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        TreeNode* lc=root->left;
        TreeNode* rc=root->right;
        
        flatten(root->left);
        flatten(root->right);
        
        root->left=NULL;
        root->right=lc; // attaching flattened 'Left Child' on roght of root
        
        TreeNode* cur=root;
        while(cur && cur->right!=NULL) cur=cur->right; // here 'Right Child' is Flattened left child of original tree
        if(cur) cur->right=rc;
    }
};

// Approach 2: Morris Traversal

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        while(root!=NULL){
            if(root->left!=NULL){
                TreeNode* lc=root->left;
                TreeNode* ol=root->left;
                
                while(lc->right!=NULL) lc=lc->right;
                
                lc->right=root->right;
                root->left=NULL;
                root->right=ol;
            }
            root=root->right;
        }
    }
};
