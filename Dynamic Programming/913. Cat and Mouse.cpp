Question Link: https://leetcode.com/problems/cat-and-mouse/

class Solution {
public:
    
    int memo[51][51][105];
    int solve(vector<vector<int>>& graph, int mouse, int cat, int moves){
        int n=graph.size();
        if(moves>2*n) return 0;
        if(mouse==cat) return 2;
        if(mouse==0) return 1;
        
        if(memo[mouse][cat][moves]!=-1) return memo[mouse][cat][moves];
        
        int ans=-1;
        
        // mouse turn
        if(moves%2==0){
            bool draw=false;
            for(int i=0;i<graph[mouse].size();i++){
                int next=graph[mouse][i];
                ans=solve(graph,next,cat,moves+1);
                if(ans==1) return memo[mouse][cat][moves]=1;
                if(ans==0) draw=true;
            }
            if(draw){
                ans=0;
            }else{
                ans=2;
            }
        }else{
            bool draw=false;
            for(int i=0;i<graph[cat].size();i++){
                int next=graph[cat][i];
                if(next==0) continue;
                ans=solve(graph,mouse,next,moves+1);
                if(ans==2) return memo[mouse][cat][moves]=2;
                if(ans==0) draw=true;
            }
            if(draw){
                ans=0;
            }else{
                ans=1;
            }
        }
        return memo[mouse][cat][moves]=ans;
    }
    
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        
        memset(memo,-1,sizeof(memo));
        return solve(graph,1,2,0);
    }
};
