class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    ll int power(ll int a, ll int b){
        if(b==0) return 1;
        if(b%2==0) return power((a%mod*a%mod)%mod,b/2)%mod;
        return (a%mod*power(a,b-1)%mod)%mod;
    }
    
    int sumSubseqWidths(vector<int>& a) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        ll int ans=0;
        for(int i=0;i<n;i++){
            ans = (ans%mod + (a[i]*power(2,i))%mod)%mod;
            ans = (ans%mod - (a[i]*power(2,n-1-i))%mod + mod)%mod;
        }
        return (int)ans;
    }
};
