Question Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int wordEnd; // count of words ending at current position
    };
    
    Trienode *root;
    
    Trienode *createNode(int idx){
        Trienode *cur = new Trienode;
        cur->ch = 'a'+idx;
        cur->wordEnd=0;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        
        return cur;
    }
    
    WordDictionary() {
        root = createNode('*'-'a');
    }
    
    void addWord(string s) {
        Trienode* cur=root;
        int idx;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    bool search(string s) {
        return isPresent(s,root);
    }
    bool isPresent(string s, Trienode* node){
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    Trienode* temp=node;
                    Trienode* cur=temp->child[j];
                    if(cur!=NULL && isPresent(s.substr(i+1),cur)) return true;
                }
                return false;
            }else{
                int idx=ch-'a';
                if(node->child[idx]==NULL) return false;
                
                node=node->child[idx];
            }
        }
        return (node->wordEnd > 0);
    }
};
