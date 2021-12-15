Question Link: https://leetcode.com/problems/implement-trie-ii-prefix-tree/

class Trie {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int wordEnd; // count of words ending at current position
        int preCount; // count of words starting with given prefix  
    };
    
    Trienode *root;
    
    Trienode *createNode(int idx){
        Trienode *cur = new Trienode;
        cur->ch = 'a'+idx;
        cur->preCount = cur->wordEnd=0;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        
        return cur;
    }
    
    map<string,int> freq;
    
    Trie() {
        root = createNode('*'-'a');
        freq.clear();
    }
    
    void insert(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur->child[idx]->preCount++;
            cur=cur->child[idx];
        }
        cur->wordEnd++;
        freq[s]++;
    }
    
    int countWordsEqualTo(string word) {
        return freq[word];
    }
    
    int countWordsStartingWith(string prefix) {
        Trienode* cur=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int idx=prefix[i]-'a';
            if(cur->child[idx]==NULL) return 0;
            
            cur=cur->child[idx];
        }
        return cur->preCount;
    }
    
    void erase(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur->child[idx]->preCount--;
            cur=cur->child[idx];
        }
        cur->wordEnd--;
        if(--freq[s]==0) freq.erase(s);
    }
};
