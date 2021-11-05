Question Link: https://leetcode.com/problems/path-sum-iii/

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
