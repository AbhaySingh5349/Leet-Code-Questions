Question Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    
    void dfs(map<string,priority_queue<string,vector<string>,greater<string>>> &graph, string src, vector<string> &path){
        
        priority_queue<string,vector<string>, greater<string>> &nbr = graph[src];
        
        while(nbr.size()>0){
            string dst=nbr.top();
            nbr.pop();
            
            dfs(graph,dst,path);
        }
        
        path.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        map<string,priority_queue<string,vector<string>, greater<string>>> graph;
        for(int i=0;i<tickets.size();i++){
            string src=tickets[i][0], dst=tickets[i][1];
            
            graph[src].push(dst);
        }
        
        string src="JFK";
        
        vector<string> path;
        dfs(graph,src,path);
        
        reverse(path.begin(),path.end());
        
        return path;
    }
};
