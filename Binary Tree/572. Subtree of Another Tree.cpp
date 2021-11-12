Question Link: https://leetcode.com/problems/subtree-of-another-tree/

// Approach 1:

class Solution {
public:
    
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        
        if(root->val!=subRoot->val) return false;
        
        return (check(root->left,subRoot->left) && check(root->right,subRoot->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        
        if(check(root,subRoot)) return true;
        return ( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};

// Approach 2:

class Solution {
public:
    
    string serialize(TreeNode* root, map<string,bool> &mp){
        if(root==NULL) return "$";
        
        string s=to_string(root->val);
        
        if(root->left==NULL && root->right==NULL){
            mp[s]=true;
            return s;
        }
        
        s+=serialize(root->left,mp);
        s+=serialize(root->right,mp);
        
        mp[s]=true;
        
        return s;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        
        map<string,bool> mp, submp;
        
        serialize(root,mp);
        string s=serialize(subRoot,submp);
        
        return (mp.find(s)!=mp.end());
    }
};
