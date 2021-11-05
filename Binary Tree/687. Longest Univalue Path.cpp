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
/*    int solve(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        
        int lans=(root->left && root->left->val==root->val ? l+1:0);
        int rans=(root->right && root->right->val==root->val ? r+1:0);
        
        ans=max(ans,lans+rans);
        
        return max(lans,rans);
    } */
    
    struct path{
        int RTNpath; // either start 
        int NTNpath;
        
        int maxlen;
        path(int RTN, int NTN, int len){
            RTNpath=RTN;
            NTNpath=NTN;
            maxlen=len;
        }
    };
    
    struct path solve(TreeNode* root){
        if(root==NULL){
            struct path cp={0,0,0};
            return cp;
        }
        struct path lp = solve(root->left);
        struct path rp = solve(root->right);
        
        int RTN=0;
        if(root->left) RTN = max(RTN,(root->left->val==root->val ? lp.RTNpath+1:0));
        if(root->right) RTN = max(RTN,(root->right->val==root->val ? rp.RTNpath+1:0));
        
        int NTN=0;
        if(root->left && root->right) NTN=max(NTN,(root->left->val==root->val ? lp.RTNpath+1:0)+(root->right->val==root->val ? rp.RTNpath+1:0));
        NTN=max(NTN,RTN);
        
        int curmax=max(NTN,max(lp.maxlen,rp.maxlen));
        
        struct path cp={RTN,NTN,curmax};
        return cp;
    }
    
    int longestUnivaluePath(TreeNode* root) {
    /*    int ans=0;
        solve(root,ans);
        return ans; */
        return solve(root).maxlen;
    }
};
