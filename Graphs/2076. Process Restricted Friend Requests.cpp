Question Link: https://leetcode.com/problems/process-restricted-friend-requests/

class Solution {
public:
    
    #define ll long long
    
    int find(vector<int> &parent, int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent,parent[u]);
    }
    
    void merge(vector<int> &parent, vector<ll int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& req) {
        vector<int> parent(n);
        vector<ll int> rk(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        vector<bool> ans(req.size(),false);
        
        for(int i=0;i<req.size();i++){
            int pu=find(parent,req[i][0]), pv=find(parent,req[i][1]);
            
            bool possible=true;
            for(int j=0;j<restrictions.size();j++){
                int x=find(parent,restrictions[j][0]), y=find(parent,restrictions[j][1]);
                if((x==pu && y==pv) || (x==pv && y==pu)){
                    possible=false;
                    break;
                }
            }
            ans[i]=possible;
            if(possible) merge(parent,rk,pu,pv); 
        }
        return ans;
    }
};
