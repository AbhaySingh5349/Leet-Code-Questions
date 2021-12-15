Question Link: https://leetcode.com/problems/short-encoding-of-words/

// Approac 1:

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        
        set<string> st;
        for(int i=0;i<n;i++) st.insert(words[i]);
        
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<s.length();j++){
                string suf=s.substr(j+1);
                if(st.find(suf)!=st.end()) st.erase(suf);
            }
        }
        
        int c=0;
        set<string> :: iterator it;
        for(it=st.begin();it!=st.end();it++){
            string s=*it;
            c+=s.length()+1;
        }
        
        return c;
    }
};

// Approac 2:

class Solution {
public:
    
    struct Trienode{
        char ch;
        Trienode *child[26]; // each node will have 26 sub-nodes
        int sufCount; // node acting as suffix
    };
    
    Trienode *root;
    
    Trienode *createNode(int idx){
        Trienode *cur = new Trienode;
        cur->ch = 'a'+idx;
        cur->sufCount=0;
        for(int i=0;i<26;i++) cur->child[i]=NULL;
        
        return cur;
    }
    
    map<Trienode*,int> mp;
    
    void addWord(string s, int k) {
        Trienode* cur=root;
        for(int i=s.length()-1;i>=0;i--){
            char ch=s[i];
            int idx=ch-'a';
            if(cur->child[idx]==NULL){
                cur->child[idx]=createNode(idx);
                cur->sufCount++;
            }
            
            cur=cur->child[idx];
        }
        mp[cur]=k;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        
    /*    set<string> st;
        for(int i=0;i<n;i++) st.insert(words[i]);
        
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<s.length();j++){
                string suf=s.substr(j+1);
                if(st.find(suf)!=st.end()) st.erase(suf); // removing words which are suffixes of other
            }
        }
        
        int c=0;
        set<string> :: iterator it;
        for(it=st.begin();it!=st.end();it++){
            string s=*it;
            c+=s.length()+1;
        }
        
        return c;  */
        
        root = createNode('*'-'a');
        
        int ans=0;
        for(int i=0;i<words.size();i++) addWord(words[i],i);
        
        map<Trienode*,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            Trienode *node=it->first;
            if(node->sufCount==0) ans+=words[mp[node]].length()+1;
        }
        return ans; 
    }
};
