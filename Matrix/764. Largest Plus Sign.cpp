Question Link: https://leetcode.com/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++) grid[mines[i][0]][mines[i][1]]=0;
        
        int dp[n][n][4];
        
        for(int i=0;i<n;i++){
            int c1=0; // count of 1s on right
            for(int j=n-1;j>=0;j--){
                c1=(grid[i][j]==0 ? 0:c1+1);
                dp[i][j][1]=c1;
            }
            
            int c3=0; // count of 1s on left
            for(int j=0;j<n;j++){
                c3=(grid[i][j]==0 ? 0:c3+1);
                dp[i][j][3]=c3;
            }
        }
        
        for(int j=0;j<n;j++){
            int c0=0; // count of 1s on top
            for(int i=0;i<n;i++){
                c0=(grid[i][j]==0 ? 0:c0+1);
                dp[i][j][0]=c0;
            }
            
            int c2=0; // count of 1s on bottom
            for(int i=n-1;i>=0;i--){
                c2=(grid[i][j]==0 ? 0:c2+1);
                dp[i][j][2]=c2;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sub1=min(dp[i][j][0],dp[i][j][2]);
                int sub2=min(dp[i][j][1],dp[i][j][3]);
                
                ans=max(ans,min(sub1,sub2));
            }
        }
        return ans;
    }
};
