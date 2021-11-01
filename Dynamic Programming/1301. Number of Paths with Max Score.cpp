class Solution {
public:
    
    int mod=1e9+7;
    vector<vector<int>> memo;
    vector<vector<int>> count;
    
    pair<int,int> solve(vector<string>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || grid[i][j]=='X') return {0,0};
        if(grid[i][j]=='E') return {0,1};
        
        if(memo[i][j]!=0) return {memo[i][j],count[i][j]};
        
        pair<int,int> p1=solve(grid,i,j-1);
        pair<int,int> p2=solve(grid,i-1,j);
        pair<int,int> p3=solve(grid,i-1,j-1);
        
        int s1=p1.first, c1=p1.second;
        int s2=p2.first, c2=p2.second;
        int s3=p3.first, c3=p3.second;
        
        int sum=max(s3,max(s1,s2));
        
        count[i][j]=((s1==sum ? c1:0)%mod + (s2==sum ? c2:0)%mod + (s3==sum ? c3:0)%mod)%mod;
        memo[i][j]=sum+(grid[i][j]=='S' ? 0:(grid[i][j]-'0'));
        
        return {memo[i][j],count[i][j]};
    }
    
    vector<int> pathsWithMaxScore(vector<string>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        memo.resize(n,vector<int>(m,0));
        count.resize(n,vector<int>(m,0));
        
        pair<int,int> p=solve(grid,n-1,m-1);
        return {p.second!=0 ? p.first:0,p.second};
    }
};
