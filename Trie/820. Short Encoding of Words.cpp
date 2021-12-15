Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

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
