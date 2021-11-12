
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth, bool isLeft=true) {
        if(depth==1){
            TreeNode* add = new TreeNode(val);
            if(isLeft){
                add->left=root;
            }else{
                add->right=root;
            }
            return add;
        }
        
        if(root==NULL) return NULL;
        
        root->left=addOneRow(root->left,val,depth-1,true);
        root->right=addOneRow(root->right,val,depth-1,false);
        
        return root;
    }
};
