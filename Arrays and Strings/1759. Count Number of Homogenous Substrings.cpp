Question Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/

class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    int countHomogenous(string s) {
        int n=s.length();
        
        ll int i=-1, j=1;
        ll int ans=1;
        while(j<n){
            if(s[j]!=s[j-1]){
                i=j-1;
                ans++;
            }else{
                ans+=(j-i);
            }
            ans%=mod;
            j++;
        }
        return (int)ans;
    }
};
