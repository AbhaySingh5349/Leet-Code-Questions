class Solution {
public:
    
    #define N 100001
    vector<pair<int,int>> graph[N];
    bool visited[100001];
    int maxd=0;
    
    void dfs(int src, int wt){
        maxd = max(maxd,wt);
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i].first;
            int t=graph[src][i].second;
            dfs(child,wt+t);
        }
    }
    
 /*   void dfs(int src,stack<int> &st){
        visited[src]=true;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i].first;
            if(visited[child]==false){
                dfs(child,st);
            }
        }
        st.push(src);
    } */
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int i,j;
        vector<int> indegree(n,0);
        for(i=0;i<n;i++){
            if(i==headID) continue;
            
            int u=manager[i];
            int v=i;
            int t=informTime[u];
            
            graph[u].push_back({v,t});
            indegree[v]++;
        }
    /*    dfs(headID,0); 
        
        return maxd; */
        
    /*    stack<int> st;
        dfs(headID,st);
        
        vector<int> dist(n,-1);
        dist[headID]=0;
        int maxd=0;
        
        while(st.size()>0){
            int u=st.top();
            st.pop();
            
            if(dist[u]!=-1){
                for(i=0;i<graph[u].size();i++){
                    int v=graph[u][i].first;
                    int t=graph[u][i].second;
                    
                    if(dist[v]<dist[u]+t){
                        dist[v]=dist[u]+t;
                        maxd=max(maxd,dist[v]);
                    }
                }
            }
        } 
        return maxd; */
        
        
        // maximum path sum in DAG
        vector<int> time(n,0);
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                int u=p.first, curTime=p.second;
                if(curTime>ans) ans=curTime;
                
                for(int i=0;i<graph[u].size();i++){
                    int v=graph[u][i].first, t=graph[u][i].second;
                    indegree[v]--;
                //    if(curTime > time[v]) time[v]=curTime;
                    if(indegree[v]==0){
                        time[v]+=t+curTime;
                        q.push({v,time[v]});
                    }
                }
            }
        }
        return ans;
    }
};
