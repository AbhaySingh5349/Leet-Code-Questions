class Solution {
public:
    
    int minSubarray(vector<int>& a, int p) {
        int n=a.size();
        
        int r=0;
        for(int i=0;i<n;i++) r = (r+a[i])%p;
        
        if(r==0) return 0;
        
        map<int,int> mp;
        mp[0]=-1;
        
        int cr=0;
        int minlen=n;
        for(int i=0;i<n;i++){
            cr=(cr+a[i])%p;
            int x=(cr-r+p)%p;
            if(mp.find(x)!=mp.end()){
                minlen=min(minlen,i-mp[x]);
            }
            mp[cr]=i;
        }
        
        if(minlen==n) return -1;
        return minlen;
    }
};
