class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int> scanline(n+2,0);
        for(int i=0;i<book.size();i++){
            int s=book[i][0], e=book[i][1], wt=book[i][2];
            scanline[s]+=wt;
            scanline[e+1]-=wt;
        }
        vector<int> ans;
        for(int i=1;i<n+1;i++){
            scanline[i]+=scanline[i-1];
            ans.push_back(scanline[i]);
        }
        
        return ans;
    }
};
