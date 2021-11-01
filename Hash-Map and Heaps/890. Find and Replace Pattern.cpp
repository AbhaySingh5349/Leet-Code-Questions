Question Link: https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    
    bool isomorphic(string s, string p){
        int n=s.length();
        map<char,char> mp;
        set<char> st;
        for(int i=0;i<n;i++){
            char pc=p[i], sc=s[i];
            
            if(mp.find(pc)!=mp.end()){
                if(sc!=mp[pc]) return false;
            }else{
                if(st.find(sc)!=st.end()) return false;
                mp[pc]=sc;
                st.insert(sc);
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            if(p.length()!=s.length()) continue;
            
            if(isomorphic(s,p)) ans.push_back(s);
        }
        return ans;
    }
};
