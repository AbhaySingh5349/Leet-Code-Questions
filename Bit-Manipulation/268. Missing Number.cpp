class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n=a.size();
        
        long long int x=0;
        for(int i=0;i<n;i++){
            x^=a[i];
            x^=i;
        }
        x^=n;
        
        return x;
    }
};
