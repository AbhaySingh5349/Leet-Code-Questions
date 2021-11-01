class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    
 /*   void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited, bool &boundary){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]=='X' || visited[i][j]) return;
        if(i==0 || j==0 || i==n-1 || j==m-1) boundary=true;
        
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            dfs(grid,x,y,visited,boundary);
        }
    }
    
    void modify(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]=='X' || visited[i][j]) return;
        
        visited[i][j]=true;
        grid[i][j]='X';
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            modify(grid,x,y,visited);
        }
    } */
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]!='O') return;
        
        grid[i][j]='#';
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            dfs(grid,x,y);
        }
    }
    
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
    /*    vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && visited[i][j]==false){
                    bool boundary=false;
                    dfs(grid,i,j,visited,boundary);
                    if(boundary==false) v.push_back({i,j});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) visited[i][j]=false;
        }
        for(int k=0;k<v.size();k++){
            int i=v[k].first, j=v[k].second;
            modify(grid,i,j,visited);
        } */
        
        
        // Boundary DFS
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O') dfs(grid,i,0);
            if(grid[i][m-1]=='O') dfs(grid,i,m-1);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O') dfs(grid,0,j);
            if(grid[n-1][j]=='O') dfs(grid,n-1,j);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                    grid[i][j]='O';
                }else if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};
