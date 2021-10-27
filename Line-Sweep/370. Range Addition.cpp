Question Link: https://leetcode.com/problems/range-addition/


class Solution {
public:
    vector<int> getModifiedArray(int len, vector<vector<int>> &updates) {
        vector<int> scanline(len+1,0);
        for(int i=0;i<updates.size();i++){
            int s=updates[i][0], e=updates[i][1], val=updates[i][2];
            scanline[s]+=val;
            scanline[e+1]-=val;
        }
        for(int i=1;i<len;i++) scanline[i]+=scanline[i-1];
        scanline.pop_back();
        return scanline;
    }
};
