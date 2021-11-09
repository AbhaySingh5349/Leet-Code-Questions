Question Link: https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n=a.size();
        
        vector<int> cs(n,1), cb(n,1);
        int maxlen=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){
                cb[i]=cs[i-1]+1;
            }else if(a[i]<a[i-1]){
                cs[i]=cb[i-1]+1;
            }else{
                cs[i]=cb[i]=1;
            }
            
            maxlen=max(maxlen,max(cs[i],cb[i]));
        }
        return maxlen;
    }
};
