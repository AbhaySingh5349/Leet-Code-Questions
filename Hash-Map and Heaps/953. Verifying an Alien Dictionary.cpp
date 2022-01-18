Question Link: https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    
    bool isPrefix(string a, string b){
        for(int i=0;i<b.length();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    bool isAlienSorted(vector<string> &words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.length();i++){
            char ch=order[i];
            mp[ch]=i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            string a=words[i], b=words[i+1];
            
            if((a.length() > b.length()) && isPrefix(a,b)) return false;
            
            for(int j=0;j<min(a.length(),b.length());j++){
                char ch1=a[j], ch2=b[j];
                if(ch1 != ch2){
                    if(mp[ch1]>mp[ch2]) return false;
                    break;
                }
            }
        }
        return true;
    }
};
