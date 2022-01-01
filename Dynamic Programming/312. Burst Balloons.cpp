Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Approach 1:

class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int> &a, int left, int right){
        if(left>right) return 0;
        
        if(memo[left][right]!=-1) return memo[left][right];
        
        int ans=0;
        for(int i=left;i<=right;i++){
            // ith is last balloon to be burst in [left,right]
            ans = max(ans,a[left-1]*a[i]*a[right+1] + solve(a,left,i-1) + solve(a,i+1,right));
        }
        
        return memo[left][right]=ans;
    }
    
    int maxCoins(vector<int> &a) {
        a.insert(a.begin(),1);
        a.push_back(1);
        
        int n=a.size();
        memo.resize(n,vector<int>(n,-1));
        
        return solve(a,1,n-2); 
    }
};

// Approach 2:

class Solution {
public:
    
    int maxCoins(vector<int> &a) {
        a.insert(a.begin(),1);
        a.push_back(1);
        
        int n=a.size();
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int len=1;len<=(n-2);len++){
            for(int left=1;left<=(n-2)-len+1;left++){
                int right=left+len-1;
                
                int ans=0;
                for(int i=left;i<=right;i++){ 
                    // ith is last balloon to be burst in [left,right]
                    int subans=dp[left][i-1] + dp[i+1][right];
                    ans=max(ans,subans+a[left-1]*a[i]*a[right+1]);
                }
                dp[left][right]=ans;
            }
        }
        return dp[1][n-2];
    }
};
