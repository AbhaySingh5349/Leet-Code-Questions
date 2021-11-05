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
