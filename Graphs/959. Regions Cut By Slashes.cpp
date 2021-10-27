class Solution {
public:
    
    int find(vector<int> &parent, int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent,parent[u]);
    }
    void merge(vector<int> &parent, vector<int> &rk, int pu, int pv){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        // '/' connects (i,j+1) and (i+1,j)
        // '\' connects (i,j) and (i+1,j+1)
        
        int n=grid.size(), m=grid[0].size();
        int dots=n+1;
        vector<int> parent(dots*dots,-1), rk(dots*dots);
        for(int i=0;i<dots*dots;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0 || j==0 || i==dots-1 || j==dots-1){
                    int id=i*dots+j;
                    merge(parent,rk,0,id); // connecting boundary points with 'zero'
                }
            }
        }
        
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==' ') continue;
                
                int id1, id2;
                if(grid[i][j]=='/'){
                    id1=i*dots+(j+1), id2=(i+1)*dots+j;
                }else if(grid[i][j]=='\\'){
                    id1=i*dots+j, id2=(i+1)*dots+(j+1);     
                }
                int pu=find(parent,id1), pv=find(parent,id2);
                if(pu==pv){
                    ans++;
                }else{
                    merge(parent,rk,pu,pv);
                }
            }
        }
        return ans;
    }
};
