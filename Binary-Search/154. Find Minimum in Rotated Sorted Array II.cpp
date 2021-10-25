Question Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
     // general test case: [2,2,2,3,3,4,4,5,6,0,1,1,1,2,2]
    // critical test cases: [10,1,10,10,10], [10,10,10,1,10], [2,0,1,1,1], [1,2,0,0,1], [1,3,3,3], [3,1,1]
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int l=0, r=n-1, idx=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(a[m]<a[(m+1)%n] && a[m]<a[(m-1+n)%n]) return a[m];
            if(a[m]<=a[(m+1)%n] && a[m]<=a[(m-1+n)%n]){
                if((idx==-1) || a[m]<a[idx]) idx=m;
            }
            
            if(a[m]>a[r]){
                // left side of peak
                l=m+1;
            }else if(a[m]<a[r]){
                // right side of peak
                r=m-1;
            }else{
                if(a[m]>a[l]){ 
                    r--;
                }else if(a[m]<a[l]){
                    l++;
                }else{
                    r--;
                    l++;
                }
            } 
        }
        
        return a[idx];
    }
};
