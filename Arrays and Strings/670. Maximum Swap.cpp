Question Link: https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while(num>0){
            int r=num%10;
            num/=10;
            v.push_back(r);
        }
        reverse(v.begin(),v.end());
        
        int n=v.size();
        
        vector<int> right(n);
        right[n-1]=n-1;
        
        for(int i=n-2;i>=0;i--){
            if(v[i]>v[right[i+1]]){
                right[i]=i;
            }else{
                right[i]=right[i+1];
            }
        }
        
        for(int i=0;i<n;i++){
            if(v[right[i]]>v[i]){
                swap(v[i],v[right[i]]);
                break;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++) ans=ans*10+v[i];
        
        return ans;
    }
};
