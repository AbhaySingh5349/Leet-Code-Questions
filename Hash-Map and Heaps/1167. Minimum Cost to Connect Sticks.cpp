Question Link:https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int connectSticks(vector<int> &a) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<a.size();i++) pq.push(a[i]);
        
        int c=0;
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            
            int second=pq.top();
            pq.pop();
            
            pq.push(first+second);
            c+=first+second;
        }
        return c;
    }
};
