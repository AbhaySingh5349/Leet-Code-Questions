class Solution {
public:
    bool search(vector<int>& a, int target) {
        int n=a.size();
        if(n==1) return (a[0]==target);
        
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(a[m]==target) return true;
            
            if(a[m]>a[r]){
                // left side of peak
                if(target>a[m] || target<a[l]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }else if(a[m]<a[r]){
                // right side of peak
                if(target<a[m] ||target>a[r]){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }else{
                if(a[m]>a[l]){
                    if(target>a[m]){
                        l++;
                    }else{
                        r--;
                    }
                }else if(a[m]<a[l]){
                    if(target>a[l]){
                        l++;
                    }else{
                        r--;
                    }
                }else{
                    r--;
                    l++;
                }
            } 
        }
        return false;
    }
};
