Question Link: https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        int n=a.size(), m=b.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        vector<int> ans;
        for(int i=0;i<m;i++){
            int f=mp[b[i]];
            ans.insert(ans.end(),f,b[i]);
            mp.erase(b[i]);
        }
        
        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            int f=it->second, val=it->first;
            ans.insert(ans.end(),f,val);
        }
        return ans;
    }
};
