Question Link: https://leetcode.com/problems/number-of-unique-good-subsequences/

class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    int numberOfUniqueGoodSubsequences(string s) {
        int n=s.length();
        
        int i=0, c0=0;
        while(i<n && s[i]=='0') i++, c0++;
        if(i==n) return 1;
        
        ll int dp[n];
        memset(dp,0,sizeof(dp));
        dp[i]=1;
        
        int idx0=-1, idx1=i;
        i++;
        while(i<n){
            dp[i]=(2*dp[i-1])%mod;
            
            if(s[i]=='0'){
                if(idx0!=-1) dp[i]= (dp[i]%mod - dp[idx0-1]%mod + mod)%mod;
                idx0=i;
                c0++;
            }else{
                if(idx1!=0) dp[i]= (dp[i]%mod - dp[idx1-1]%mod + mod)%mod;
                idx1=i;
            }
            i++;
        }
        return dp[n-1]+(c0!=0);
    }
};
