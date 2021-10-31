class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n<3) return 0;
    /*    int c=0;
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                int d=(a[j]-a[i])/(len-1);
                bool pos=true;
                for(int k=i+1;k<=j;k++){
                    if(a[k]-a[k-1]!=d){
                        pos=false;
                        break;
                    }
                }
                if(pos==true){
                    c++;
                }
            }
        }
        return c;  */
        
        int c=0;
    /*    int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==a[i-1]-a[i-2]) dp[i]=dp[i-1]+1;
            c+=dp[i];
        }
        return c; */
        
        int prev=0, cur=0;
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==a[i-1]-a[i-2]){
                cur=prev+1;
            }else{
                cur=0;
            }
            c+=cur;
            prev=cur;
        }
        return c;
    }
};
