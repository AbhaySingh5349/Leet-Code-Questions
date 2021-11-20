Question Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        if(m*n!=a.size()) return {};
        
        vector<vector<int>> ans(m,vector<int>(n));
        
        int i=0, j=0;
        for(int k=0;k<a.size();k++){
            if(j==n) i++,j=0;
            
            ans[i][j]=a[k];
            j++;
        }
        return ans;
    }
};
