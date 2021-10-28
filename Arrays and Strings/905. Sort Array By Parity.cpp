Question Link: https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size();
        int i=0, j=0;
        while(j<n){
            while(i<n && a[i]%2==0) i++;
            j=max(i,j);
            j++;
            if(j<n && a[j]%2==0) swap(a[i],a[j]);
        }
        return a;
    }
};
