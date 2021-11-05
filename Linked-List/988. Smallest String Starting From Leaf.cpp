class Solution {
public:
    
 /*   void solve(TreeNode* root, string s, vector<string> &v){
        if(root==NULL) return;
        
        char ch=root->val+'a';
        s+=ch;
        
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            v.push_back(s);
            return;
        }
        
        solve(root->left,s,v);
        solve(root->right,s,v);
    } */
    
 /*   void solve(TreeNode* root, string s, string &ans){
        if(root==NULL) return;
        
        char ch=root->val+'a';
        s+=ch;
        
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            if(ans.length()==0 || ans>s) ans=s;
            return;
        }
        
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    } */
    
    void solve(TreeNode* root, string s, string &ans){
        if(root==NULL) return;
        
        char ch=root->val+'a';
        s=ch+s;
        
        if(root->left==NULL && root->right==NULL){
            if(ans.length()==0 || ans>s) ans=s;
            return;
        }
        
        solve(root->left,s,ans);
        solve(root->right,s,ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL) return "";
        
        // extra space, O(n*logn)
    /*    vector<string> v;
        solve(root,"",v);
        
        sort(v.begin(),v.end());
        return v[0]; */
        
        // O(1) space
    /*    string ans="";
        solve(root,"",ans); */
        
        string ans="";
        solve(root,"",ans);
        
        return ans;
    }
};
