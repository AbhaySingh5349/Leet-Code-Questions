class Solution {
public:
    
    //basically we need to find distinct indexed pairs with sum=k
    int maxOperations(vector<int>& a, int k) {
        int n=a.size();
        
    /*    sort(a.begin(),a.end());
        int c=0, i=0, j=n-1;
        
        while(i<j){
            int sum=a[i]+a[j];
            if(sum<k){
                i++;
            }else if(sum>k){
                j--;
            }else{
                c++; // count of disjoint pairs
                i++,j--;
            }
        }
        return c; */
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        int c=0;
        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            int x=it->first, f=it->second;
            int y=k-x;
            if(mp.find(y)!=mp.end()){
                if(x==y){
                    c+=f/2;
                }else{
                    int val=min(mp[x],mp[y]);
                    c+=val;
                    mp[x]-=val;
                    mp[y]-=val;
                }
            }
        }
        
        return c; 
    }
};
