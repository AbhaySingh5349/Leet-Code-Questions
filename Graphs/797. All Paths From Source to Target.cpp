Question Link: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    void path(vector<vector<int>> &graph, int src, int dst, vector<int> &cur, vector<vector<int>> &ans, vector<bool> &visited){
        visited[src]=true;
        cur.push_back(src);
        
        if(src==dst){
            ans.push_back(cur);
            
            visited[src]=false;
            cur.pop_back();
            return;
        }
        
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false) path(graph,child,dst,cur,ans,visited);
        }
        
        visited[src]=false;
        cur.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> cur;
        
        vector<bool> visited(n,false);
        path(graph,0,n-1,cur,ans,visited);
        
        return ans;
    }
};
