Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        
        int dxy[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int len=1;
        
        set<pair<int,int>> visited;
        visited.insert({0,0});
        
        while(q.size()>0){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                
                int i=p.first, j=p.second;
                if(i==n-1 && j==n-1) return len;
                
                for(int k=0;k<8;k++){
                    int x=i+dxy[k][0], y=j+dxy[k][1];
                    if(x>=0 && y>=0 && x<n && y<n && visited.find({x,y})==visited.end() && grid[x][y]==0){
                        visited.insert({x,y});
                        q.push({x,y});
                    }
                }
            }
            len++;
        }
        return -1;
    }
};
