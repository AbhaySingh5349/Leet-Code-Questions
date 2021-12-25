Question Link: https://leetcode.com/problems/longest-duplicate-substring/

class Solution {
public:
    
    struct TrieNode{
        char ch;
        TrieNode *child[26];
        TrieNode(int idx){
            this->ch = 'a'+idx;
            for(int i=0;i<26;i++) this->child[i]=NULL;
        }
    };
    
    TrieNode *root;
    
    bool insert(string s){
        TrieNode *cur = root;
        bool possible=true;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL){
                possible=false;
                cur->child[idx]=new TrieNode(idx);
            }
            cur=cur->child[idx];
        }
        return possible;
    }
    
    string longestDupSubstring(string s) {
        string ans="";
        int n=s.length();
        
        int l=1, r=n-1;
        while(l<r){
            int len=l+(r-l+1)/2;
            
            root = new TrieNode('*'-'a');
            bool found=false;
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                string sub="";
                for (int k=i;k<=j;k++) sub+=s[k];
                if(insert(sub)){
                    ans=sub;
                    found=true;
                    break;
                }
            }
            
            if(found){
                l=len;
            }else{
                r=len-1;
            }
        }
        return ans;
    }
};
