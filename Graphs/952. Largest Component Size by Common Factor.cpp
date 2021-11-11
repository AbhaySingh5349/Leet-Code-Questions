class Solution {
public:
    
    // smallest prime factor
    vector<int> sieve(int n){
        vector<int> spf(n);
        for(int i=0;i<n;i++) spf[i]=i;
        
        for(int i=2;i*i<=n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<n;j+=i) if(spf[j]>i) spf[j]=i;
            }
        }
        return spf;
    }
    
    vector<int> primeFactors(vector<int> &spf, int num){
        vector<int> factors;
        while(num>1){
            factors.push_back(spf[num]);
            num/=spf[num];
        }
        return factors;
    }
    
    int find(vector<int> &parent, int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent,parent[u]);
    }
    
    void merge(vector<int> &parent, vector<int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    int largestComponentSize(vector<int>& a) {
        int n=a.size();
        
        int maxe=*max_element(a.begin(),a.end());
        vector<int> spf=sieve(maxe+1);
        
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            vector<int> factors=primeFactors(spf,a[i]);
            for(int j=0;j<factors.size();j++){
                int f=factors[j];
                if(f>1) mp[f].push_back(a[i]); // grouping all the numbers having common factors
            }
        }
        
        vector<int> parent(maxe+1), rk(maxe+1);
        for(int i=0;i<maxe+1;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        map<int,vector<int>> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            vector<int> v=it->second;
            for(int i=0;i<v.size()-1;i++){
                int pu=find(parent,v[i]), pv=find(parent,v[i+1]);
                if(pu!=pv) merge(parent,rk,pu,pv);
            } 
        }
        int ans=*max_element(rk.begin(),rk.end());
        return ans;
    }
};
