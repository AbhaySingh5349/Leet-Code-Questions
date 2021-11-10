Question Link: https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        int n=capital.size();
        
        priority_queue<pair<int,int>> ppq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> cpq;
        
        for(int i=0;i<n;i++) cpq.push({capital[i],i});
        
        while(k>0){
            while(cpq.size()>0 && cpq.top().first<=w){
                int idx=cpq.top().second;
                cpq.pop();
                
                ppq.push({profit[idx],idx});
            }
            if(ppq.size()==0) break;
            
            w+=ppq.top().first;
            ppq.pop();
            k--;
        }
        return w;
    }
};
