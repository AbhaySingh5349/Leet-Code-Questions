Question Link: https://leetcode.com/problems/unique-paths/

// Approach 1:

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0, j=0;j<n;j++) dp[i][j]=1;
        for(int j=0, i=0;i<m;i++) dp[i][j]=1;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++) dp[i][j]=dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1]; 
    }
};

// Approach 2:

class Solution {
public:
    
    int ncr(int n, int r){
        long long int ans=1;
        for(int i=0;i<r;i++){
            ans *= (n-i);
            ans /= (i+1);
        }
        return (int) ans;
    }
    
    int uniquePaths(int m, int n) {
        
        return ncr(m+n-2,min(n-1,m-1));
    }
};
