class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n=a.size();
        
        vector<int> left(n);
        left[0]=a[0];
        for(int i=1;i<n;i++) left[i]=max(left[i-1],a[i]);
        
        vector<int> right(n);
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) right[i]=min(right[i+1],a[i]);
        
        int i=0;
        while(i<n-1 && left[i]>right[i+1]) i++;
        
        return (i+1);
    }
};
