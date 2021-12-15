Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class WordFilter {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        vector<int> index; // idx of all strings prefix / sufix upto current node
    };
    
    Trienode *preRoot, *sufRoot;
    
    Trienode *createNode(int idx){
        Trienode *cur = new Trienode;
        cur->ch = 'a'+idx;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        cur->index.clear();
        
        return cur;
    }

    void insert(string s, int k, bool isPrefix){
        Trienode* root;
        
        if(isPrefix){
            root=preRoot;
        }else{
            root=sufRoot;
        }
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(root->child[idx]==NULL) root->child[idx]=createNode(idx);
            
            root->child[idx]->index.push_back(k);
            root=root->child[idx];
        }
    }
    
    vector<int> wordStartingWith(string s, bool isPrefix){
        Trienode* root;
        
        if(isPrefix){
            root=preRoot;
        }else{
            root=sufRoot;
        }
        
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(root->child[idx]==NULL) return {};
            
            root=root->child[idx];
        }
        return root->index;
    }
    
    WordFilter(vector<string>& words) {
        preRoot = createNode('*'-'a');
        sufRoot = createNode('*'-'a');
        
        for(int i=0;i<words.size();i++){
            string s=words[i];
            
            insert(s,i,true);
            
            reverse(s.begin(),s.end());
            insert(s,i,false);
        }
    }
    
    int f(string prefix, string suffix) {
        int maxlen=0;
        
        vector<int> plist = wordStartingWith(prefix,true);
        
        reverse(suffix.begin(),suffix.end());
        vector<int> slist = wordStartingWith(suffix,false);
        
        int i=plist.size()-1, j=slist.size()-1;
        while(i>=0 && j>=0){
            if(plist[i]>slist[j]){
                i--;
            }else if(slist[j]>plist[i]){
                j--;
            }else{
                return plist[i];
            }
        }
        return -1;
    }
};
