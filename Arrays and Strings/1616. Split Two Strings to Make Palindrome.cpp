Question Link: https://leetcode.com/problems/split-two-strings-to-make-palindrome/

class Solution {
public:
    
    bool palindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    bool check(string a, string b){
        int n=a.length();
        
        int i=0, j=n-1;
        while(i<j){
            if(a[i]!=b[j]) return palindrome(a,i,j) || palindrome(b,i,j);
            i++, j--;
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        
        return check(a,b) || check(b,a);
    }
};
