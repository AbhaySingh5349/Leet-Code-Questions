class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    ll int getMin(ll int a, ll int b){
        if(a<=b) return a;
        return b;
    }
    
    int sumOfFlooredPairs(vector<int>& a) {
        int n=a.size();
        
        int N=1e5+1;
        vector<ll int> freq(N,0);
        for(int i=0;i<n;i++) freq[a[i]]++;
        
        for(int i=1;i<N;i++) freq[i]+=freq[i-1];
        
        // this way we are repeating same procedure for repeating elements, we can avoid this using Frequencies of each element
     /*   ll int ans=0;
        for(ll int i=0;i<n;i++){
            ll int sum=0;
            for(ll int j=1;j*a[i]<N;j++){
                ll int lb=(long)a[i]*j, ub=getMin(1e5,(long)a[i]*(j+1)-1);
                ll int c=freq[ub]-(lb>0 ? freq[lb-1]:0);
                
                sum = (sum%mod + ((c%mod)*(j%mod))%mod)%mod; 
            }
            ans = (ans%mod+sum%mod)%mod;
        } 
        return (int)ans; */
        
        ll int ans=0;
        for(ll int i=1;i<N;i++){
            // considering i as denominator and j as floor value
            if(freq[i]-freq[i-1]>0){
                // if value=i exists in array
                ll int sum=0;
                for(ll int j=1;j*i<N;j++){
                    // lb,rb is range of elements which can be present if we chose i as denominator and j as floor
                    ll int lb=i*j, ub=getMin(1e5,i*(j+1)-1);
                    ll int c=freq[ub]-(lb>0 ? freq[lb-1]:0);

                    sum = (sum%mod + (c*j)%mod)%mod; 
                }
                ll int c=freq[i]-freq[i-1]; // number of occurances of current element = i in array
                ans = (ans%mod+(sum*c)%mod)%mod;
            }
        }
        return (int)ans;
    }
};
