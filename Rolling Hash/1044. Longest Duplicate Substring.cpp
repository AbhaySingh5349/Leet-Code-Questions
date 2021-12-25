Question Link: https://leetcode.com/problems/longest-duplicate-substring/

// Approach 1:

class Solution {
public:
    
    bool isPossible(string s, int len, string &ans){
        int n=s.length();
        map<string,int> mp;
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;
            string sub="";
            for (int k=i;k<=j;k++) {
                sub+=s[k];
            }
            if(mp.find(sub)!=mp.end()){
                ans=sub;
                return true;
            }
            mp[sub]++;
        }
        return false;
    } 
    
    string longestDupSubstring(string s) {
        int n=s.length();
        
        // O(n^3)
        map<string,int> mp;
        for (int len=1;len<=n;len++) {
            // starting point 
            for (int i=0; i<n-len+1; i++) {
                int j=i+len-1; // ending point
                string sub="";
                for (int k=i;k<=j;k++) {
                    sub+=s[k];
                }
                mp[sub]++;
            }
        }
        map<string,int> :: iterator it;
        int maxlen=0;
        string ans="";
        for(it=mp.begin();it!=mp.end();it++){
            string sub=it->first;
            int f=mp[sub];
            if(f>1){
                int len=sub.length();
                if(len>maxlen){
                    maxlen=len;
                    ans=sub;
                }
            }
        }
        return ans; 
        
        // O(n^2logn)
        int l=0, r=n-1;
        string ans="";
        while(l<r){
            int m=l+(r-l+1)/2;
            if(isPossible(s,m,ans)){
                l=m;
            }else{
                r=m-1;
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

// Approach 3:

class Solution {
public:
    
    #define ll long long
    
    ll int power(ll int a, ll int b, ll int mod){
        ll int ans=1L;
        while(b>0){
            if(b%2){
                ans=(ans*a)%mod;
                b--;
            }else{
                a=(a*a)%mod;
                b/=2;
            }
        }
        return ans;
    }
    bool isPossible(string s, int len, string &ans, ll int mod1, ll int mod2){
        int n=s.length();
        set<pair<ll int,ll int>> st;
        ll int hash1=0, hash2=0;
        for(int i=0;i<len;i++){
            hash1=(hash1*26+(s[i]-'a'))%mod1;
            hash2=(hash2*26+(s[i]-'a'))%mod2;
        }
        st.insert({hash1,hash2});
        
        ll int pow1=power(26,len,mod1);
        ll int pow2=power(26,len,mod2);
        for(int i=len;i<n;i++){
            hash1=((hash1*26+(s[i]-'a'))%mod1-((s[i-len]-'a')*pow1)%mod1 +mod1)%mod1;
            hash2=((hash2*26+(s[i]-'a'))%mod2-((s[i-len]-'a')*pow2)%mod2 +mod2)%mod2;
            if(st.find({hash1,hash2})!=st.end()){
                ans=s.substr(i-len+1,len);
                return true;
            }
            st.insert({hash1,hash2});
        }
        return false;
    } 
    
    string longestDupSubstring(string s) {
        int n=s.length();
        
        int l=0, r=n-1;
        string ans="";
        int mod1=1e9+5, mod2=1e9+7;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(isPossible(s,m,ans,mod1,mod2)){
                l=m;
            }else{
                r=m-1;
            } 
        }
        return ans;
    }
};
