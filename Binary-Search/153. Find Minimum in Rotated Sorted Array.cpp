class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(a[m]<a[(m+1)%n] && a[m]<a[(m-1+n)%n]) return a[m];
            
            if(a[m]>a[n-1]){
                // left side of peak
                l=m+1;
            }else{
                // right side of peak
                r=m-1;
            }
        }
        return -1;
    }
};
