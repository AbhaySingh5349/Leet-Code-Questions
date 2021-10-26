class Solution {
public:
    bool isLongPressedName(string s, string p) {
        int i,j;
        int n=s.length(), m=p.length();
        
        i=0, j=0;
        while(i<n && j<m){
            if(s[i]!=p[j]) return false;
            i++, j++;
            
            int c1=0, c2=0;
            while(i<n && s[i]==s[i-1]){
                c1++;
                i++;
            }
            while(j<m && p[j]==p[j-1]){
                c2++;
                j++;
            }
            if(c1>c2) return false;
        }
        if(i!=n || j!=m) return false;
        return true;
    }
};
