class Solution {
public:
    
    void dfs(vector<int> graph[],int src,int parent,int &time,vector<int> &arrivalTime,vector<int> &minArrivalTime,vector<vector<int>> &ans){
        arrivalTime[src]=time;
        minArrivalTime[src]=time;
        time++;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(child==parent) continue;

        /*    if(arrivalTime[child]==-1){ // Tree-edge
                dfs(graph,child,src,time,arrivalTime,minArrivalTime,ans);
                
                if(minArrivalTime[child]>arrivalTime[src]){ // Bridge-edge (src --- child)
                    ans.push_back({src,child});
                } 
                minArrivalTime[src]=min(minArrivalTime[src],minArrivalTime[child]);
            }else{ // Forward-edge or Back-edge
                minArrivalTime[src]=min(minArrivalTime[src],minArrivalTime[child]);
            } */
            
            if(arrivalTime[child]==-1){
                dfs(graph,child,src,time,arrivalTime,minArrivalTime,ans);
                if(minArrivalTime[child]>arrivalTime[src]) ans.push_back({src,child});
            }
            minArrivalTime[src]=min(minArrivalTime[src],minArrivalTime[child]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> arrivalTime(n,-1), minArrivalTime(n,-1);
        int src=0, time=0;
        vector<vector<int>> ans;
        dfs(graph,src,-1,time,arrivalTime,minArrivalTime,ans);
        return ans;
    }
};
