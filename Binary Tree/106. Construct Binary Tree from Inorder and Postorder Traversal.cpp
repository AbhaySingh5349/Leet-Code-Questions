Question Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    
    TreeNode* solve(vector<int>& post, vector<int>& in, int &idx, int s, int e){
        int n=post.size();
        if(s>e || idx==-1) return NULL;
        
        TreeNode *root = new TreeNode(post[idx]);
        
        int k=-1;
        for(int i=s;i<=e;i++){
            if(post[idx]==in[i]){
                k=i;
                break;
            }
        }
        idx--;
        
        root->right = solve(post,in,idx,k+1,e);
        root->left = solve(post,in,idx,s,k-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int> &in, vector<int> &post) {
        int n=post.size();
        
        int idx=n-1;
        return solve(post,in,idx,0,n-1);
    }
};
