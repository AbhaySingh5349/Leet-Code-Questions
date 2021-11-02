Question Link: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    
    #define ll long long
    
    ll int ncr(int n, int r){
        if(n<r) return 0;
        ll int ans=1L;
        
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        return (int)ncr(m+n-2,min(n,m)-1);
    }
};
