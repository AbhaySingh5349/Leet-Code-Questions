Question Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

class Solution {
public:

    struct path{
        int INCpath; // child node bigger
        int DECpath; // child node smaller
        int maxlen; // overall max length possible
    };

    struct path solve(TreeNode* root){
        if(root==NULL) return {0,0,0};

        struct path lp=solve(root->left);
        struct path rp=solve(root->right);

        int val=root->val;

        // for increasing path
        int inc=1;
        if(root->left!=NULL && root->left->val==val+1) inc=max(inc,lp.INCpath+1);
        if(root->right!=NULL && root->right->val==val+1) inc=max(inc,rp.INCpath+1);

        // for decreasing path
        int dec=1;
        if(root->left!=NULL && root->left->val+1==val) dec=max(dec,lp.DECpath+1);
        if(root->right!=NULL && root->right->val+1==val) dec=max(dec,rp.DECpath+1);

        int len=max(max(inc,dec),max(rp.maxlen,lp.maxlen));

        if(root->left!=NULL && root->right!=NULL) len=max(len,inc+dec-1);
        
        return {inc,dec,len};
    }

    int longestConsecutive2(TreeNode * root) {
        return solve(root).maxlen;
    }
};
