Question Link: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    int lengthOfLIS(vector<int> &a) {
        int n=a.size();
        
        int dp[n];
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]) dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};
