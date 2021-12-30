Question Link: https://leetcode.com/problems/min-cost-climbing-stairs/

// Approach 1:

class Solution {
public:
    
    map<int,int> mp;
    
    int cost(vector<int> &a, int idx){
        int n=a.size();
        if(idx>=n) return 0;
        
        if(mp.find(idx)!=mp.end()) return mp[idx];
        
        int ans=a[idx];
        ans += min(cost(a,idx+1),cost(a,idx+2));
        
        return mp[idx]=ans;
    }
    
    int minCostClimbingStairs(vector<int> &a) {
        return min(cost(a,0),cost(a,1));
    }
};
