Question Link: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &dfsVisited){
        visited[src]=true; // all the nodes visited in multiple DFS calls
        dfsVisited[src]=true; // nodes visited in current DFS call
        
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(dfs(graph,child,visited,dfsVisited)) return true;
            }else{
                if(dfsVisited[child]==true) return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    } 
 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> visited(n,false), dfsVisited(n,false);
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfs(graph,i,visited,dfsVisited)==false) ans.push_back(i);
        } 
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &dfsVisited, set<int> &cycle){
        visited[src]=true;
        dfsVisited[src]=true;
        
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(dfs(graph,child,visited,dfsVisited,cycle)){
                    cycle.insert(child);
                    return true;
                }
            }else{
                if(dfsVisited[child]==true){
                    cycle.insert(child);
                    return true;
                }
            }
        }
        dfsVisited[src]=false;
        return false;
    }
 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> visited(n,false), dfsVisited(n,false);
        
        set<int> cycle; // nodes who are part of some cycle
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(dfs(graph,i,visited,dfsVisited,cycle)) cycle.insert(i);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(cycle.find(i)==cycle.end()) ans.push_back(i);
        }
        return ans;
    }
};
