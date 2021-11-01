Question Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        int n=a.size();
        if(n%k) return false;
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        sort(a.begin(),a.end());
        int i=0;
        while(i<n){
            int x=a[i];
            if(mp.find(x)==mp.end()){
                i++;
                continue;
            } 
            
            int c=k;
            while(mp.find(x)!=mp.end() && c!=0){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                x++;
                c--;
            }
            if(c!=0) return false;
        }
        return true;
    }
};
