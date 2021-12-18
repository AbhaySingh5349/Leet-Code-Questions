Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class StreamChecker {
public:
    
    struct TrieNode{
        char ch;
        TrieNode *child[26];
        int wordEnd;
    };
    
    TrieNode *root;
    
    TrieNode *create(int idx){
        TrieNode *cur = new TrieNode;
        cur->ch = 'a' + idx;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        cur->wordEnd=0;
        
        return cur;
    }
    
    void insert(string s){
        TrieNode *cur = root;
        for(int i=s.length()-1;i>=0;i--){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=create(idx);
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    StreamChecker(vector<string>& words) {
        root = create('*'-'a');
        
        for(int i=0;i<words.size();i++) insert(words[i]);
    }
    
    string stream="";
    
    bool query(char letter) {
        stream += letter;
        
        TrieNode *cur = root;
        for(int i=stream.length()-1;i>=0;i--){
            int idx=stream[i]-'a';
            
            if(cur->child[idx]==NULL) return false;
            if(cur->child[idx]->wordEnd>0) return true;
            
            cur=cur->child[idx];
        } 
        return false; // as we have char in Trie but not in stream having ending in Trie
    }
};
