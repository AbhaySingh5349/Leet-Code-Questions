class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        vector<int> left(n,a[0]);
        for(int i=1;i<n;i++) left[i]=a[i]+(left[i-1]>0 ? left[i-1]:0);
        
        vector<int> right(n,a[n-1]);
        for(int i=n-2;i>=0;i--) right[i]=a[i]+(right[i+1]>0 ? right[i+1]:0);
        
        int maxsum=accumulate(a.begin(),a.end(),0);
        for(int i=1;i<n-1;i++){
            int sum=max(left[i-1]+right[i+1],max(left[i-1],right[i+1]));
            maxsum=max(maxsum,sum);
        }
        maxsum=max(maxsum,max(right[1],left[n-2]));
        
        return maxsum;
    }
};
