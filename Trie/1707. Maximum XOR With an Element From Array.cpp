Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    
    struct TrieNode{
        TrieNode *left, *right;
        TrieNode(){
            left=NULL;
            right=NULL;
        }
    };
    
    TrieNode *root;
    
    TrieNode *createNode(){
        return new TrieNode();
    }
    
    void insert(int val){
        int bitIdx=30;
        TrieNode *cur=root;
        
        while(bitIdx>=0){
            int mask = (1<<bitIdx);
            int bit = ((mask & val)>0 ? 1:0);
            
            if(bit==0){
                if(cur->left==NULL) cur->left = createNode();
                cur=cur->left;
            }else{
                if(cur->right==NULL) cur->right = createNode();
                cur=cur->right;
            }
            bitIdx--;
        }
    }
    
    int querry(int find){
        int bitIdx=30;
        TrieNode *cur=root;
        
        int ans=0;
        while(bitIdx>=0){
            int mask = (1<<bitIdx);
            int bit = ((mask & find)>0 ? 1:0); // required bit to get max possible answer
            
            if(bit==0){
                if(cur->left!=NULL){
                    cur=cur->left;
                }else{
                    ans |= (1<<bitIdx);
                    cur=cur->right;
                }
            }else{
                if(cur->right!=NULL){
                    ans |= (1<<bitIdx);
                    cur=cur->right;
                }else{
                    cur=cur->left;
                }
            }
            bitIdx--;
        }
        return ans;
    }
    
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int search(vector<int> &a, int maxval){
        int idx=-1;
        int l=0, r=a.size()-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(a[m]<=maxval){
                idx=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return idx;
    }
    
    vector<int> maximizeXor(vector<int> &a, vector<vector<int>>& queries) {
        
        root = createNode();
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),compare);
        
        vector<int> ans(queries.size(),-1);
        int prev=-1;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0], maxval=queries[i][1], k=queries[i][2];
            
            int idx=search(a,maxval);
            
            if(idx!=-1){
                for(int j=prev+1;j<=idx;j++) insert(a[j]);
                prev=idx;
            }
            
            int requiredNum = INT_MAX ^ val;
            int sub=(idx==-1 ? -1:querry(requiredNum));
            if(idx!=-1) ans[k]=sub^val;
        }
        return ans;
    }
};
