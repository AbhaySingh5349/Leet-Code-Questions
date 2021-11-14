Question Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/

class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n=s.length();
        
        int col=n/rows;
        
        string ans="";
        for(int i=0;i<col;i++){
            string cur="";
            for(int j=i;j<n;j+=(1+col)) cur+=s[j];
            ans+=cur;
        }
        while(ans.back()==' ') ans.pop_back();
        
        return ans;
    }
};
