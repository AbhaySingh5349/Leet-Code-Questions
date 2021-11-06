class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int n=a.size();
        if(n==2) return a;
        
        long long int x=0;
        for(int i=0;i<n;i++) x^=a[i]; // xor of entire array = xor of elements occuring once
        
        int num1=0, num2=0;
        
        long long int rmsb=x&(-x); // right most set bit 
        
        for(int i=0;i<n;i++){
            if(a[i]&rmsb){
                num1^=a[i];
            }else{
                num2^=a[i];
            }
        }
        return {num1,num2};
    }
};
