Question Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        int n=a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int r=a[i]%k;
            if(r<0) r+=k;
            mp[r]++;
        }
        
        for(int i=0;i<n;i++){
            int r=a[i]%k;
            if(r<0) r+=k;
            int f=mp[r];
            
            if(r==0 || 2*r==k){
                if(f%2!=0) return false;
            }else{
                int cr=k-r;
                if(mp.find(cr)==mp.end()){
                    return false;
                }else{
                    int cf=mp[cr];
                    if(f!=cf) return false;
                }
            }
        }
        return true;
    }
};
