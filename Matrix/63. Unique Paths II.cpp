Question Link: https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        if(grid[0][0]==1) return 0;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0, j=0;j<m;j++){
            if(grid[i][j]==1) break;
            dp[i][j]=1;
        }
        for(int j=0, i=0;i<n;i++){
            if(grid[i][j]==1) break;
            dp[i][j]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1) continue;
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
