class Solution {
public:
    
    bool possible(vector<int> &a, int start){
        int n=a.size();
        for(int i=0;i<n;i++){
            start+=a[i];
            if(start<1) return false;
        }
        return true;
    }
    
    int minStartValue(vector<int>& a) {
        int n=a.size();
        
    /*    int l=1, r=1e4+1;
        while(l<r){
            int m=l+(r-l)/2;
            if(possible(a,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l; */
        
        int ans=1, sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            ans=max(ans,1-sum);
        }
        return ans;
    }
};
