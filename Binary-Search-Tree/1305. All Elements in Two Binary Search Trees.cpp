Question Link: https://leetcode.com/problems/trapping-rain-water/

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
