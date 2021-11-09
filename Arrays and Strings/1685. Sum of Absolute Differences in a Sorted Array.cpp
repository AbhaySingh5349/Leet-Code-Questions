Question Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

1. Considering Left --> Right movement

let i=number of element to left of current
since the array is sorted, increment in current difference will be i*(a[i]-a[i-1])
    
2.Considering Right --> Left movement

let (n-i-1)=number of element to right of current
since the array is sorted, increment in current difference will be (n-i-1)*(a[i+1]-a[i])

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& a) {
        int n=a.size();
        
        vector<int> left(n,0);
        for(int i=1;i<n;i++) left[i]=left[i-1]+(a[i]-a[i-1])*i;
        
        vector<int> right(n,0);
        for(int i=n-2;i>=0;i--) right[i]=right[i+1]+(a[i+1]-a[i])*(n-i-1);
        
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]=left[i]+right[i];
        
        return ans;
    }
};
