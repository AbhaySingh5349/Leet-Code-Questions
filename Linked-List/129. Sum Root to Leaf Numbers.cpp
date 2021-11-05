class Solution {
public:
    
    void solve(TreeNode* root, int cur, int &ans){
        if(root==NULL) return;
        
        cur=cur*10+(root->val);
        if(root->left==NULL && root->right==NULL){
            ans+=cur;
            return;
        }
        
        solve(root->left,cur,ans);
        solve(root->right,cur,ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};
