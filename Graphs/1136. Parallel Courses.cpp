Question Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>> &edges) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u-1].push_back(v-1);
            indegree[v-1]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int c=0;
        while(q.size()>0){
            int size=q.size();
            n-=size;
            while(size--){
                int u=q.front();
                q.pop();
                
                for(int v:graph[u]){
                    indegree[v]--;
                    if(indegree[v]==0) q.push(v);
                }
            }
            c++;
        }
        return (n==0 ? c:-1);
    }
};
