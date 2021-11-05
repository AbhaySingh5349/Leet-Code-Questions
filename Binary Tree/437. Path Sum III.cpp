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
    void solve(TreeNode* root, int target, int &s, map<int,int> &m, int &c){
        if(root==NULL) return;
        
        s+=root->val;
        if(m.find(s-target)!=m.end()) c+=m[s-target];
        
        m[s]++;
        
        solve(root->left,target,s,m,c);
        solve(root->right,target,s,m,c);
        
        m[s]--;
        s-=root->val;
    }
    
    int pathSum(TreeNode* root, int target) {
        int c=0, s=0;
        map<int,int> m;
        m[0]=1;
        solve(root, target, s, m, c);
        
        return c;
    }
};
