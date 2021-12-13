Question Link: https://leetcode.com/problems/invert-binary-tree/

// Approach 1:

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

// Approach 2:

class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            int size=q.size();
            while(size--){
                TreeNode *cur=q.front();
                q.pop();
                
                TreeNode *nl=cur->right, *nr=cur->left;
                
                if(nr!=NULL) q.push(nr);
                if(nl!=NULL) q.push(nl);
                
                cur->left=nl;
                cur->right=nr;
            } 
        }
        return root;
    }
};
