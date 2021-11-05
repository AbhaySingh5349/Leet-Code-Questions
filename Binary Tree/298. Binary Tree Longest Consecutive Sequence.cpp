class Solution {
public:
    
    struct path{
        int INCpath; // child node bigger
        int maxlen;
    };

    struct path solve(TreeNode* root){
        if(root==NULL) return {0,0};

        struct path lp=solve(root->left);
        struct path rp=solve(root->right);

        int val=root->val;

        // for increasing path
        int inc=1;
        if(root->left!=NULL && root->left->val==val+1) inc=max(inc,lp.INCpath+1);
        if(root->right!=NULL && root->right->val==val+1) inc=max(inc,rp.INCpath+1);

        int len=max(inc,max(rp.maxlen,lp.maxlen));
        
        return {inc,len};
    }

    int longestConsecutive(TreeNode * root) {
        return solve(root).maxlen;
    }
};
