Question Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/

class Solution {
public:
    string kthDistinct(vector<string>& a, int k) {
        int n=a.size();
        
        map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(mp[a[i]]==1) k--;
            if(k==0) return a[i];
        }
        return "";
    }
};
