class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    int numSub(string s) {
        int n=s.length();
        
        ll int i=-1, j=0;
        ll int ans=0;
        while(j<n){
            if(s[j]=='0'){
                i=j;
            }else{
                ans+=(j-i);
            }
            ans%=mod;
            j++;
        }
        return (int)ans;
    }
};
