Question Link: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

class Solution {
public:
    
    #define ll long long
    
    int maxSumRangeQuery(vector<int> &a, vector<vector<int>> &req) {
        int n=a.size();
        vector<ll int> scanline(n+1,0); // storing effect of range occuring in requests
        
        for(int i=0;i<req.size();i++){
            int s=req[i][0], e=req[i][1];
            scanline[s]++;
            scanline[e+1]--;
        }
        for(int i=1;i<n;i++) scanline[i]+=scanline[i-1];
        
        sort(scanline.begin(),scanline.end(),greater<int>());
        sort(a.begin(),a.end(),greater<int>());
        
        ll int sum=0;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++) sum=(sum%mod + (scanline[i]*a[i])%mod)%mod;
        
        return (int)sum;
    }
};
