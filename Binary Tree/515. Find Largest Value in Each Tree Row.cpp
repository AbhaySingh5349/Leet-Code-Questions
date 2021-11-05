Question Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> ans;
        while(q.size()>0){
            int size=q.size();
            int maxval=INT_MIN;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                
                maxval=max(maxval,node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxval);        }
        return ans;
    }
};
