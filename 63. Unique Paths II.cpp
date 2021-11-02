class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=(grid[0][0]==1 ? 0:1);
        for(int i=0,j=1;j<m;j++){
            if(grid[i][j]==1){
                break;
            }else{
                dp[i][j]+=dp[i][j-1];
            }
        }
        for(int i=1,j=0;i<n;i++){
            if(grid[i][j]==1){
                break;
            }else{
                dp[i][j]+=dp[i-1][j];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0){
                    dp[i][j]+=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
