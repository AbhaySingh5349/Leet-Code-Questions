Question Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

// Approach 1:

class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int> &a, int left, vector<int> &mul, int idx){
        int n=a.size(), m=mul.size();
        
        if(idx==m) return 0;
        
        if(memo[left][idx]!=-1) return memo[left][idx];
        
        int right=n-1-(idx-left);
        
        int ans= max(a[left]*mul[idx] + solve(a,left+1,mul,idx+1), a[right]*mul[idx] + solve(a,left,mul,idx+1));
        
        return memo[left][idx]=ans;
    }
    
    int maximumScore(vector<int> &a, vector<int> &mul) {
        int n=a.size();
        
        if(n==1) return mul[0]*a[0];
        
        int m=mul.size();
        memo.resize(m,vector<int>(m,-1));
        return solve(a,0,mul,0);
    }
};

// Approach 2:

class Solution {
public:
    
    int maximumScore(vector<int> &a, vector<int> &mul) {
        int n=a.size();
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for(int idx=m-1;idx>=0;idx--){
            for(int left=idx;left>=0;left--){
                int right=n-1-(idx-left);
                dp[left][idx] = max(a[left]*mul[idx] + dp[left+1][idx+1], a[right]*mul[idx] + dp[left][idx+1]);
            }
        }
        return dp[0][0];
    }
};
