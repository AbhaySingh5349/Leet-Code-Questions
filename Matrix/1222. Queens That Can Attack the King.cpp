class Solution {
public:
       
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        set<pair<int,int>> st;
        for(int i=0;i<queens.size();i++) st.insert({queens[i][0],queens[i][1]});
        
        int dxy[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        
        vector<vector<int>> ans;
        for(int k=0;k<8;k++){
            int x=king[0], y=king[1];
            int dx=dxy[k][0], dy=dxy[k][1];
            while(x+dx>=0 && x+dx<8 && y+dy>=0 && y+dy<8){
                x+=dx, y+=dy;
                if(st.find({x,y})!=st.end()){
                    ans.push_back({x,y});
                    break;
                }
            }
        }
        return ans;
    }
};
