class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &pzl) {
        map<char,vector<int>> mp; // words containing current char
        
        for(int i=0;i<words.size();i++){
            int mask=0;
            for(int j=0;j<words[i].size();j++){
                int bit=(words[i][j]-'a');
                mask |= (1<<bit);
            }
            set<char> st;
            for(int j=0;j<words[i].size();j++){
                char ch=words[i][j];
                if(st.find(ch)!=st.end()) continue;
                mp[ch].push_back(mask);
                st.insert(ch);
            }
        }
        
        vector<int> ans(pzl.size(),0);
        
        for(int i=0;i<pzl.size();i++){
            int mask=0;
            
            for(int j=0;j<pzl[i].size();j++){
                int bit=(pzl[i][j]-'a');
                mask |= (1<<bit);
            }
            
            char fch=pzl[i][0];
            int c=0;
            if(mp.find(fch)!=mp.end()){
                vector<int> v=mp[fch]; // mask of all words containg first char of puzzle
                for(int j=0;j<v.size();j++){
                    int wordMask=v[j];
                    if((wordMask & mask) == wordMask) c++;
                }
            }
            ans[i]=c;
        }
        return ans;
    }
};
