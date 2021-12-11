Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int> &a) {
        int n=a.size();
        
        vector<int> right(n);
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],a[i]);
        
        int ans=0;
        int left=a[0];
        for(int i=0;i<n-1;i++){
            left=min(left,a[i]);
            ans=max(ans,right[i+1]-left);
        }
        return ans;
    }
};
