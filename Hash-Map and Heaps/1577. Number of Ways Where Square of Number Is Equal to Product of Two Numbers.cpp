Question Link: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

class Solution {
public:
    
    #define ll long long
    
    int numTriplets(vector<int> &a, vector<int> &b) {
        int n=a.size(), m=b.size();
        
        map<ll int,int> ma, mb;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ll int p=(long)a[i]*a[j];
                ma[p]++;
            }
        }
        
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                ll int p=(long)b[i]*b[j];
                mb[p]++;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ll int p=(long)a[i]*a[i];
            if(mb.find(p)!=mb.end()) ans+=mb[p];
        }
        
        for(int i=0;i<m;i++){
            ll int p=(long)b[i]*b[i];
            if(ma.find(p)!=ma.end()) ans+=ma[p];
        }
        return ans;
    }
};
