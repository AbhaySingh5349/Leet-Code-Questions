Question Link: https://leetcode.com/problems/longest-word-in-dictionary/

// Approach 1:

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        
        int n=words.size();
        string ans="", cur="";
        int maxlen=0;
        
        set<string> st;
        for(int i=0;i<n;i++){
            string s=words[i];
            cout<<s<<"  ";
            string sub=s.substr(0,s.length()-1);
            
            if(s.length()==1 || st.find(sub)!=st.end()){
                if(s.length()>ans.length()) ans=s;
                st.insert(s);
            }
        }
        return ans;
    }
};

// Approach 2:

class Solution {
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
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL) cur->child[idx]=create(idx);
            cur=cur->child[idx];
        }
        cur->wordEnd++;
    }
    
    bool search(string s){
        TrieNode *cur = root;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a'; // checking each and every prefix present for particular string [0,i]
            if(cur->child[idx]==NULL || cur->child[idx]->wordEnd==0) return false;
            cur=cur->child[idx];
        }
        return true;
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        
        int n=words.size();
        
        string ans="";
        
        root = create('*'-'a');
        for(int i=0;i<n;i++) insert(words[i]);
        
        for(int i=0;i<n;i++){
            if((words[i].length()==1 || search(words[i])) && words[i].length()>ans.length()) ans=words[i];
        }
        return ans;
    }
};
