Question Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

// Appraoch 1:

class Solution {
public:
    
    void inorder(TreeNode* root, vector<int> &v){
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            while(root && root->left!=NULL){
                st.push(root->left);
                root=root->left;
            }
            TreeNode* p=st.top();
            st.pop();
            
            v.push_back(p->val);
            if(p->right!=NULL){
                st.push(p->right);
                root=p->right;
            }else{
                root=NULL;
            }
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1,a), inorder(root2,b);
        
        vector<int> ans;
        int n=a.size(), m=b.size();
        int i=0, j=0;
        
        while(i<n || j<m){
            int x = (i<n ? a[i]:INT_MAX), y = (j<m ? b[j]:INT_MAX);
            
            if(x<=y){
                ans.push_back(x);
                i++;
            }else{
                ans.push_back(y);
                j++;
            }
        }
        return ans;
    }
};

// Appraoch 2:

class Solution {
public:
    
    void insertLeft(TreeNode* &root, stack<TreeNode*> &st){
        while(root && root->left!=NULL){
            st.push(root->left);
            root=root->left;
        }
    }
    
    void insertRight(TreeNode* &cur, TreeNode* &root, stack<TreeNode*> &st){
        if(cur!=NULL && cur->right!=NULL){
            st.push(cur->right);
            root=cur->right;
        }else{
            root=NULL;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans;
        
        stack<TreeNode*> st1, st2;
        if(root1!=NULL) st1.push(root1);
        if(root2!=NULL) st2.push(root2);
        
        while(st1.size()>0 || st2.size()>0){
            insertLeft(root1,st1), insertLeft(root2,st2);
            
            TreeNode *p = (st1.size()>0 ? st1.top():NULL), *q = (st2.size()>0 ? st2.top():NULL);
            if(st1.size()>0) st1.pop();
            if(st2.size()>0) st2.pop();
            
            int x = (p!=NULL ? p->val:INT_MAX), y = (q!=NULL ? q->val:INT_MAX);
            
            if(x<=y){
                ans.push_back(x);
                insertRight(p,root1,st1);
                if(q!=NULL) st2.push(q);
                root2=NULL;
            }else{
                ans.push_back(y);
                insertRight(q,root2,st2);
                if(p!=NULL) st1.push(p);
                root1=NULL;
            }
        }
        
        return ans;
    }
};
