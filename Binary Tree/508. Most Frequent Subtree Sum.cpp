Question Link: https://leetcode.com/problems/most-frequent-subtree-sum/

class Solution {
public:
    
    int solve(TreeNode* root, map<int,int> &mp){
        if(root==NULL) return 0;
        
        int ls=solve(root->left,mp);
        int rs=solve(root->right,mp);
        
        int sum=ls+rs+root->val;
        mp[sum]++;
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        int sum=solve(root,mp);
        
        map<int,int> :: iterator it;
        
        int maxf=0;
        vector<int> v;
        for(it=mp.begin();it!=mp.end();it++){
            int val=it->first, f=it->second;
            
            if(f>maxf){
                v.clear();
                v.push_back(val);
            }else if(f==maxf){
                v.push_back(val);
            }
            maxf=max(f,maxf);
        }
        return v;
    }
};
