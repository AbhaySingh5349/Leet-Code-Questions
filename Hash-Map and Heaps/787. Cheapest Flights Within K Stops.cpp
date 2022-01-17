Question Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Approach 1: O(V^2 .log V)

class Solution {
public:
    
    struct node{
        int cost;
        int u;
        int curStops;
    };
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.cost > b.cost;
        }
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int vertices=n, edges=flights.size();
        vector<pair<int,int>> graph[n];
        int i,j;
        for(i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            graph[u].push_back(make_pair(v,w));
        }
         
        priority_queue<node,vector<node>,compare> pq;
        struct node p={0,src,0};
        pq.push(p);
        
        vector<int> price(n,INT_MAX), stops(n,INT_MAX);
        price[src]=0, stops[src]=0;
        
        while(pq.size()>0){ O(V^2 .log V)
            p=pq.top();
            pq.pop();
            int curCost=p.cost, u=p.u, curStops=p.curStops;
            
            if(u==dst) return curCost;
            if(curStops>k) continue;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, cost=graph[u][i].second;
                if(price[v]>curCost+cost){
                    price[v]=curCost+cost;
                    stops[v]=curStops+1;
                    p={price[v],v,stops[v]};
                    pq.push(p);
                }else if(stops[v]>curStops+1){
                    price[v]=curCost+cost;
                    stops[v]=curStops+1;
                    p={price[v],v,stops[v]};
                    pq.push(p);
                }
            }
        }
        return -1;
    }
};

// Approach 2: O(K⋅E)

class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int vertices=n, edges=flights.size();
        vector<pair<int,int>> graph[n];
        int i,j;
        for(i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            graph[u].push_back(make_pair(v,w));
        }
        
        vector<vector<int>> dp(n,vector<int>(k+2,INT_MAX)); // price to reach ith city with atmost j allowed routes/edges
        for(int j=0;j<k+2;j++) dp[src][j]=0;
        
        for(int j=1;j<k+2;j++){ // Bellman Ford Algorithm
            for(vector<int> &flight : flights){
                int u=flight[0], v=flight[1], cost=flight[2];
                if(dp[u][j-1]<INT_MAX){
                    dp[v][j]=min(dp[v][j],dp[u][j-1]+cost);
                }
            }
        }
        return (dp[dst][k+1]==INT_MAX ? -1:dp[dst][k+1]);
    }
};
