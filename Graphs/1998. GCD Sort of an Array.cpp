class Solution {
public:
    
    int find(vector<int> &parent, int u){
        if(parent[u]==u) return u;
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
    
    // spf[x] is the smallest prime factor of number x, where x >= 2
    vector<int> sieve(int n){
        vector<int> spf(n);
        for(int i=0;i<n;i++) spf[i]=i; // O(N)
        
        for(int i=2;i*i<n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<n;j+=i){
                    if(spf[j]>i) spf[j]=i; // update to the smallest prime factor of j
                }
            }
        }
        return spf;
    }
    
     // O(logN)
    vector<int> primeFactors(vector<int> &spf, int n){
        vector<int> factors;
        while(n>1){
            factors.push_back(spf[n]);
            n/=spf[n];
        }
        return factors;
    }
    
    bool gcdSort(vector<int>& a) {
        int n=a.size();
        
        int maxe=*max_element(a.begin(),a.end());
        
        vector<int> spf=sieve(maxe+1);
        vector<int> parent(maxe+1), rk(maxe+1);
        for(int i=0;i<maxe+1;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        for(int i=0;i<n;i++){
            vector<int> factors=primeFactors(spf,a[i]);
            for(int j=0;j<factors.size();j++){
                int pu=find(parent,a[i]), pv=find(parent,factors[j]);
                if(pu!=pv) merge(parent,rk,pu,pv);
            }
        } 
        
        vector<int> sortedArr(a);
        sort(sortedArr.begin(), sortedArr.end());
        for (int i=0; i<n;i++){
            int pu=find(parent,a[i]), pv=find(parent,sortedArr[i]);
            if(pu!=pv) return false;
        } 
        return true;
    }
};
