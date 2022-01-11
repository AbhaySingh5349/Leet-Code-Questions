Question Link: https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    
    int sum(TreeNode* root, int cur){
        if(root==NULL) return 0;
        
        int val=(cur<<1) | root->val;
        
        if(root->left==NULL && root->right==NULL) return val;
        
        return sum(root->left,val) + sum(root->right,val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return sum(root,0);
    }
};
