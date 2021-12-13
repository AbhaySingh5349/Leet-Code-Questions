Question Link: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path){
        if(root==NULL) return false;
        
        path.push_back(root);
        if(root==node) return true;
        
        if(getPath(root->left,node,path) || getPath(root->right,node,path)) return true;
        
        path.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        getPath(root,p,path1);
        getPath(root,q,path2);
        
        TreeNode* ans=NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            TreeNode *n1=path1[i], *n2=path2[i];
            
            if(n1==n2) ans=n1;
        }
        return ans;
    }
};
