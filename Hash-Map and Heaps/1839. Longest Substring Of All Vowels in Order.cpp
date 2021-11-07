class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n=s.length();
        
        map<char,int> mp;
        mp['a']=0, mp['e']=1, mp['i']=2, mp['o']=3, mp['u']=4;
        
        map<char,int> cur;
        int prev=-1;
        
        int i=0, j=0;
        int maxlen=0;
        while(j<n){
            char ch=s[j];
            int idx=mp[ch];
            
            if(prev!=idx-1 && prev!=idx){
                cur.clear();
                prev=-1;
                if(idx!=0) j++;
                i=j;
                continue;
            }
            
            cur[s[j]]++;
            if(prev==idx-1) prev=idx;
            if(cur.size()==5) maxlen=max(maxlen,j-i+1);
            
            j++;
        }
        return maxlen;
    }
};
