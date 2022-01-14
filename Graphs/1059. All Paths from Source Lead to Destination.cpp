Question Link: https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

class Solution {
public:
    
    bool solve(vector<int> graph[], int src, int dst, vector<bool> &visited, vector<bool> &dfsVisited){
        if(graph[src].size()==0) return (src==dst); // vice versa doesnt wordk : eg. [[0,1],[0,2]] : 0 --> 2
        
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto child : graph[src]){
            if(visited[child]==false){
                if(solve(graph,child,dst,visited,dfsVisited)==false) return false;
            }else{
                if(dfsVisited[child]==true) return false; // if cycle exists : means infinte no. of paths
            }
        }
        dfsVisited[src]=false;
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int src, int dst) {
        
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
        }
        
        if(graph[src].size()==0) return (src==dst);
        
        vector<bool> visited(n,false);
        visited[src]=true;
        for(auto child : graph[src]){
            vector<bool> dfsVisited(n,false);
            if(solve(graph,child,dst,visited,dfsVisited)==false) return false;
        }
        return true;
    }
};
