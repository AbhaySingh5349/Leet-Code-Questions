Question Link: https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    
    int nextGreaterElement(int n) {
        vector<int> a(10);
        int i=9;
        while(n>0){
            if(i<0) return -1;
            a[i--]=n%10;
            n/=10;
        }
        
        int s=i+1, e=9;
        while(e>s){
            if(a[e]>a[e-1]) break;
            e--;
        }
        
        if(s==e) return -1;
        
        int pos1=e-1, pos2=e;
        while(e<10){
            if(a[e]>a[pos1] && a[e]<a[pos2]) pos2=e;
            e++;
        }
        swap(a[pos1],a[pos2]);
        sort(a.begin()+pos1+1,a.end());
        
        long long int ans=0;
        for(int i=s;i<10;i++) ans=ans*10+a[i];
        
        
        if(ans>INT_MAX) return -1;
        return ans;
    }
};
