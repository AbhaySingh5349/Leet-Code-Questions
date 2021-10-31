Question Link: https://leetcode.com/problems/distinct-subsequences/

// Approach 1:

class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(string s, string p, int i, int j){
        int n=s.length(), m=p.length();
        if(j==m) return 1;
        if(i==n) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans=0;
        if(s[i]==p[j]) ans+=(memo[i+1][j+1]!=-1 ? memo[i+1][j+1]:solve(s,p,i+1,j+1));
        ans+=(memo[i+1][j]!=-1 ? memo[i+1][j]:solve(s,p,i+1,j)); // either i,j matched or not matched
        
        return memo[i][j]=ans;
    }
    
    int numDistinct(string s, string p) {
        int n=s.length(), m=p.length();
        
        memo.resize(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};

// Approach 2:

class Solution {
public:
    
    int numDistinct(string s, string p) {
        int n=s.length(), m=p.length();
        
        unsigned int dp[n+1][m+1];
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        for(int j=1;j<m+1;j++) dp[0][j]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
