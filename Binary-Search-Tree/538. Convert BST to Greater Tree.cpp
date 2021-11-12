Question Link: https://leetcode.com/problems/convert-bst-to-greater-tree/

class Solution {
public:
    
    int update(TreeNode* root, int &sum){
        if(root==NULL) return 0;
        
        int oval=root->val;
        
        int rs=update(root->right,sum);
        
        root->val+=sum;
        sum+=oval;
        
        int ls=update(root->left,sum);
        
        return oval+ls+rs;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        update(root,sum);
        
        return root;
    }
};
