class Solution {
public:
    
    #define ll long long
    
    int minPatches(vector<int>& a, int n) {
        int i=0;
        
        ll int maxreach=0;
        int c=0;
        while(maxreach<n){
            if(i==a.size()){
                // add next smallest missing number i.e (maxreach+1)
                maxreach += (maxreach+1);
                c++;
            }else{
                if(a[i]<=maxreach+1){
                    maxreach+=a[i];
                    i++;
                }else{
                    // add next smallest missing number i.e (maxreach+1)
                    maxreach += (maxreach+1);
                    c++;
                }
            }
        }
        return c;
    }
};
