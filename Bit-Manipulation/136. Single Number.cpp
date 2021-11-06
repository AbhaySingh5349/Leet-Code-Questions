class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n=a.size();
        
        long long int x=0;
        for(int i=0;i<n;i++) x^=a[i];
        
        return x;
    }
};
