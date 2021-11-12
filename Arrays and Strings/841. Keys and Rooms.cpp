Question Link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& a) {
        int n=a.size();
        
        set<int> visited;
        visited.insert(0);
        
        queue<int> q;
        q.push(0);
        
        while(q.size()>0){
            int idx=q.front();
            q.pop();
            
            for(int i=0;i<a[idx].size();i++){
                int key=a[idx][i];
                if(visited.find(key)==visited.end()){
                    visited.insert(key);
                    q.push(key);
                }
            }
        }
        return (visited.size()==n);
    }
};
