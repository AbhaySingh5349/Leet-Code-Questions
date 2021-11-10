Question Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
public:
    
    void dfs(int src, vector<int> &v, map<int,vector<int>> &graph, set<int> &visited){
        v.push_back(src);
        visited.insert(src);
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited.find(child)==visited.end()){
                dfs(child,v,graph,visited);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,vector<int>> graph;
        map<int,int> deg;
        
        for(int i=0;i<a.size();i++){
            int u=a[i][0], v=a[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        
        int src;
            
        map<int,int> :: iterator it;
        for(it=deg.begin();it!=deg.end();it++){
            int node=it->first;
            if(deg[node]==1){
                src=node;
                break;
            }
        }
        
        vector<int> v;
        set<int> visited;
        dfs(src,v,graph,visited);
        return v;
    }
};
