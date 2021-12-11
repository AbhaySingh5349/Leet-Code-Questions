Question Link: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &idx, int s, int e){
        int n=pre.size();
        if(s>e || idx==n) return NULL;
        
        TreeNode *root = new TreeNode(pre[idx]);
        
        int k=-1;
        for(int i=s;i<=e;i++){
            if(pre[idx]==in[i]){
                k=i;
                break;
            }
        }
        idx++;
        root->left = solve(pre,in,idx,s,k-1);
        root->right = solve(pre,in,idx,k+1,e);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        
        int idx=0;
        return solve(pre,in,idx,0,n-1);
    }
};
