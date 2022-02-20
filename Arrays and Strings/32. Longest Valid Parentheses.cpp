Question Link: https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    int longestValidParentheses(string s) {
        int  n=s.length();
        
        int ans=0;
        int open=0, close=0;
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                open++;
            }else{
                close++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }else if(close>open){
                open=close=0;
            }
        }
        
        open=0, close=0;
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            if(ch==')'){
                close++;
            }else{
                open++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }else if(open>close){
                open=close=0;
            }
        }
        return ans;
    }
};
