Question Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

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
        int bitIdx=31;
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
        int bitIdx=31;
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
    
    int findMaximumXOR(vector<int> &a) {
        int n=a.size();
        
        root = new TrieNode();
        for(int i=0;i<n;i++) insert(a[i]);
        
        int ans=0;
        for(int i=0;i<n;i++){
            int requiredNum = INT_MAX ^ a[i];
            int val = querry(requiredNum);
            ans = max(ans,val^a[i]);
        }
        return ans;
    }
};
