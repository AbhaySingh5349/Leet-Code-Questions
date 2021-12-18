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
