Question Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        if(n<2){
            for(int i=0;i<n;i++) ans.push_back(i);
            return ans;
        }
        
        vector<int> graph[n], indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            
            graph[u].push_back(v), graph[v].push_back(u);
            indegree[v]++, indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==1) q.push(i);
        
        int node=n;
        while(node>2){
            int size=q.size();
            node-=size;
            while(size--){
                int u=q.front();
                q.pop();

                for(int v : graph[u]){
                    indegree[v]--;
                    if(indegree[v]==1) q.push(v);
                }
            }
        }
        
        while(q.size()>0){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
