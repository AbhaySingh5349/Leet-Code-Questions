class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        
        vector<int> count(n,0);
        vector<int> prev(n,-1), next(n,n);
        
        int left=-1;
        if(s[0]=='*') count[0]=1;
        if(s[0]=='|') left=0;
        prev[0]=left;
        
        for(int i=1;i<n;i++){
            if(s[i]=='*'){
                count[i]=count[i-1]+1;
            }else{
                count[i]=count[i-1];
                left=i;
            }
            prev[i]=left;
        }
        
        int right=n;
        if(s[n-1]=='|') right=n-1;
        next[n-1]=right;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='|') right=i;
            next[i]=right;
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0], r=queries[i][1];
            l=max(next[l],l);
            r=min(prev[r],r);
            
            if(l<r && l>=0 && r<n){
                ans.push_back(count[r]-count[l]);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
