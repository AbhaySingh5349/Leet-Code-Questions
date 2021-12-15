Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

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
