class Solution {
public:
    int maximumGap(vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        
        int mine=a[0], maxe=a[0];
        for(int i=1;i<n;i++){
            mine=min(mine,a[i]);
            maxe=max(maxe,a[i]);
        }
        
        int bucketSize=(maxe-mine)/(n-1) + ((maxe-mine)%(n-1)!=0);
        
        vector<int> maxVal(n-1,INT_MIN), minVal(n-1,INT_MAX);
        
        for(int i=0;i<n;i++){
            if(a[i]==mine || a[i]==maxe) continue;
            
            int idx=(a[i]-mine)/bucketSize;
           
            maxVal[idx]=max(maxVal[idx],a[i]);
            minVal[idx]=min(minVal[idx],a[i]);
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            int curMin=minVal[i];
            if(curMin!=INT_MAX) ans=max(ans,curMin-mine);
            
            int curMax=maxVal[i];
            if(curMax!=INT_MIN) mine=curMax; // max(mine,curMax)
        }
        ans=max(ans,maxe-mine);
        return ans;
    }
};
