Question Link: https://leetcode.com/problems/replace-words/

// Approac 1:

class Solution {
public:
    
    bool isPresent(string s, map<int,vector<string>> &mp, vector<string> &v){
        int len=s.length();
        if(mp.find(len)==mp.end()) return false;
        
        vector<string> sub=mp[len];
        for(int i=0;i<sub.size();i++){
            if(s==sub[i]){
                v.push_back(s);
                return true;
            }
        }
        return false;
    }
    
    void update(string s, map<int,vector<string>> &mp, vector<string> &v){
        string sub="";
        bool found=false;
        for(int i=0;i<s.length();i++){
            sub+=s[i];
            if(isPresent(sub,mp,v)){
                found=true;
                break;
            }
        }
        if(found==false) v.push_back(s);
    }
    
    string replaceWords(vector<string>& dict, string s) {
        map<int,vector<string>> mp;
        for(int i=0;i<dict.size();i++) mp[dict[i].length()].push_back(dict[i]);
        
        int i=0, n=s.length();
        
        vector<string> v;
        while(i<n){
            string sub="";
            while(i<n && isalpha(s[i])) sub+=s[i++];
            
            update(sub,mp,v);
            i++;
        }
        string ans="";
        for(int i=0;i<v.size();i++) ans+=v[i]+" ";
        
        return ans.substr(0,ans.length()-1);
    }
};

// Approach 2:

class Solution {
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
    
    void insert(string s) {
        Trienode* cur=root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=createNode(idx);
            
            cur=cur->child[idx];
        }
        cur->wordEnd+=1;
    }
    
    void update(string s, vector<string> &v){
        Trienode* cur=root;
        bool found=false;
        int i=0;
        while(i<s.length()){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) break;
            
            cur=cur->child[idx];
            if(cur->wordEnd > 0){
                found=true;
                break;
            }
            i++;
        }
        if(found==true) s=s.substr(0,i+1);
        
        v.push_back(s);
    }
    
    string replaceWords(vector<string>& dict, string s) {
        
        root = createNode('*'-'a');
        
        for(int i=0;i<dict.size();i++) insert(dict[i]);
        
        int i=0, n=s.length();
        
        vector<string> v;
        while(i<n){
            string sub="";
            while(i<n && isalpha(s[i])) sub+=s[i++];
            
            update(sub,v);
            i++;
        }
        string ans="";
        for(int i=0;i<v.size();i++) ans+=v[i]+" ";
         
        return ans.substr(0,ans.length()-1); 
    }
};
