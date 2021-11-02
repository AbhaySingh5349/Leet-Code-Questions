Question Link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int n1=0, maxp=1;
        bool hasPositive=false, hasZero=false;
        int pos[n], neg[n];
        if(a[0]>0){
            hasPositive=true;
            pos[0]=a[0], neg[0]=1;
        }else if(a[0]<0){
            pos[0]=1, neg[0]=a[0];
            if(a[0]==-1) n1++;
        }else{
            hasZero=true;
            pos[0]=1, neg[0]=1;
        }
        maxp = max(maxp,pos[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>0){
                pos[i]=pos[i-1]*a[i];
                neg[i]=(neg[i-1]==1 ? 1:neg[i-1]*a[i]);
                hasPositive=true;
            }else if(a[i]<0){
                pos[i]=(neg[i-1]==1 ? 1:neg[i-1]*a[i]);
                neg[i]=pos[i-1]*a[i];
                
                if(a[i]==-1) n1++;
            }else{
                hasZero=true;
                pos[i]=1, neg[i]=1;
            }
            maxp = max(maxp,pos[i]);
        }
        if(maxp==1){
            if(hasPositive || (n1>0 && n1%2==0)){
                return maxp;
            }
            if(hasZero){
                return 0;
            }
        }
        return maxp;
    }
};

// Approach 2:

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int pp=1, np=1, maxp=1;
        int n1=0;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                hasPositive=true;
                pp*=a[i];
                np=(np==1 ? 1:np*a[i]);
            }else if(a[i]<0){
                int t=pp;
                pp=(np==1 ? 1:np*a[i]);
                np=t*a[i];
                if(a[i]==-1){
                    n1++;
                }
            }else{
                hasZero=true;
                pp=1, np=1;
            }
            
            maxp=max(maxp,pp);
        }
        
        if(maxp==1){
            if(hasPositive || (n1>0 && n1%2==0)){
                return maxp;
            }
            if(hasZero){
                return 0;
            }
        }
        return maxp; 
    }
};

// Approach 3:

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int dpmax[n], dpmin[n];
        memset(dpmax,0,n), memset(dpmin,INT_MAX,n);
        
        dpmax[0]=dpmin[0]=a[0];
        int ans=dpmax[0];
        for(int i=1;i<n;i++){
            dpmax[i]=max(a[i],max(dpmax[i-1]*a[i],dpmin[i-1]*a[i]));
            dpmin[i]=min(a[i],min(dpmax[i-1]*a[i],dpmin[i-1]*a[i]));
            
            ans=max(dpmax[i],ans);
            cout<<dpmax[i]<<","<<dpmin[i]<<" ";
        }
        return ans; 
    }
};

// Approach 4:

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int dpmax, dpmin, ans;
        ans=dpmax=dpmin=a[0];
        
        for(int i=1;i<n;i++){
            int newmax, newmin;
            newmax=max(a[i],max(dpmax*a[i],dpmin*a[i]));
            newmin=min(a[i],min(dpmax*a[i],dpmin*a[i]));
            
            ans=max(newmax,ans);
            dpmax=newmax, dpmin=newmin;
        }
        return ans; 
    }
};
