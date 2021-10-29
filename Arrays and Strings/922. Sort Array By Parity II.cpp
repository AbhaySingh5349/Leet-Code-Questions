Question Link: https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int n=a.size();
        
        int i=0, j=0;
        while(j<n){
            while(i<n && a[i]%2==i%2) i++;
            j=max(i,j);
            j++;
            if(j<n && a[j]%2!=j%2) swap(a[i],a[j]);
        }
        
        return a;
    }
};
