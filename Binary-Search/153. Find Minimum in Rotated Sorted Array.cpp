Question Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Approach 1:

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
                l=m+1; // left side of peak
            }else{
                r=m-1; // right side of peak
            }
        }
        return -1;
    }
};

// Approach 2:

class Solution {
public:
    
    int findMin(vector<int> &a) {
        int n=a.size();
        if(a[0]<a[n-1] || n==1) return a[0];
        
        int l=0, r=n-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(a[m]<a[(m+1)%n] && a[m]<a[(m-1+n)%n]) return a[m];
            
            if(a[m]>=a[0]){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return -1;
    }
};
