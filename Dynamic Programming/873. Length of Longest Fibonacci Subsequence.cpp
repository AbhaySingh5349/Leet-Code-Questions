Question Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n=a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]=i;
        
        int dp[n][n];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++) dp[i][j]=2;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int val=a[i]+a[j];
                if(mp.find(val)!=mp.end()){
                    int k=mp[val];
                    dp[j][k]=dp[i][j]+1;
                }
            }
        }
        
        int maxlen=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++) maxlen=max(maxlen,dp[i][j]);
        }
        
        return (maxlen==2 ? 0:maxlen);
    }
};
