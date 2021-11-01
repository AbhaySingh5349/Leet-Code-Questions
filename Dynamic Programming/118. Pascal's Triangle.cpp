class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> grid[n];
        
        grid[0].resize(1);
        grid[0][0]=1;
        
        vector<vector<int>> ans;
        ans.push_back({1});
        
        for(int i=1;i<n;i++){
            grid[i].resize(i+1);
            for(int j=0;j<=i;j++){
                grid[i][j]=(j!=i ? grid[i-1][j]:0)+(j-1 >=0 ? grid[i-1][j-1]:0);
            } 
            ans.push_back(grid[i]);
        }
        return ans; 
    }
};
