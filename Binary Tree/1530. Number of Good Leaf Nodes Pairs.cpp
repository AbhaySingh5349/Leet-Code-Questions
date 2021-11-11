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
    
 /*   void getDepth(TreeNode* root, map<TreeNode*,int> &node, vector<TreeNode*> &leaf, int d){
        if(root==NULL) return;
        
        node[root]=d;
        
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root);
            return;
        }
        
        getDepth(root->left,node,leaf,d+1);
        getDepth(root->right,node,leaf,d+1);
    }
    
    TreeNode* getLCA(TreeNode* root, TreeNode* one, TreeNode* two){
        if(root==NULL) return NULL;
        
        if(root==one || root==two) return root;
        
        TreeNode* lc=getLCA(root->left,one,two);
        TreeNode* rc=getLCA(root->right,one,two);
        
        if(lc!=NULL && rc!=NULL) return root;
        
        return (lc!=NULL ? lc:rc);
    } */
    
    vector<int> solve(TreeNode* root, int maxd, int &c){
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {1};
        
        vector<int> left=solve(root->left,maxd,c);
        vector<int> right=solve(root->right,maxd,c);
        
        for(int l : left){
            for(int r : right){
                if(l+r<=maxd) c++;
            }
        }
        
        vector<int> par;
        for(int l : left) if(l+1<=maxd) par.push_back(l+1);
        for(int r : right) if(r+1<=maxd) par.push_back(r+1);
        
        return par;
    }
    
    int countPairs(TreeNode* root, int maxd) {
    /*    map<TreeNode*,int> node;
        vector<TreeNode*> leaf;
        getDepth(root,node,leaf,0);
        
        int c=0;
        for(int i=0;i<leaf.size()-1;i++){
            for(int j=i+1;j<leaf.size();j++){
                TreeNode* lca=getLCA(root,leaf[i],leaf[j]);
                int d=node[leaf[i]]+node[leaf[j]]-2*node[lca];
                
                if(d<=maxd) c++;
            }
        }
        return c; */
        
        int c=0;
        solve(root,maxd,c);
        return c;
    }
};
