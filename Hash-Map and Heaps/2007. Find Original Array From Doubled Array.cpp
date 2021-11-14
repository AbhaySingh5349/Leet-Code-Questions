Question Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n=a.size();
        
        if(n%2!=0) return {};
        
        map<int,int> mp;
        int zero=0;
        sort(a.begin(),a.end());
        
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(a[i]==0){
                zero++;
            }
        }
        if(zero%2==1) return {};
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int x=a[i], fx=mp[a[i]];
            if(x==0 || fx==0) continue;
            
            int y=2*x;
            if(mp.find(y)!=mp.end()){
                int fy=mp[y];
                if(fy>0){
                    ans.push_back(x);
                    mp[x]--;
                    mp[y]--;
                }
            }
        }
        
        while(zero>0){
            ans.push_back(0);
            zero-=2;
        }
        
        if(ans.size()==n/2) return ans;
        return {};
    }
};
