Question Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n=a.size();
        
        vector<int> pre(n,0);
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=a[i]^pre[i-1];
        
        int m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1]; 
            int val=(pre[r]^(l>0 ? pre[l-1]:0));
            ans[i]=val;
        } 
        return ans;
    }
};
