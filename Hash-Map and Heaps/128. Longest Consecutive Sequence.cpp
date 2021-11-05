class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        
    /*    sort(a.begin(),a.end());
        
        int c=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1){
                c++;
            }else if(a[i]==a[i-1]){
                
            }else{
                c=1;
            }
            ans=max(ans,c);
        }
        return ans; */
        
        unordered_map<int,bool> mp; // can current element be end of any sequence
        for(int i=0;i<n;i++) mp[a[i]]=true;
        
        for(int i=0;i<n;i++){
            if(mp.find(a[i]+1)!=mp.end()) mp[a[i]]=false;
        }
        
    /*    int ans=1;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end() || mp[a[i]]==false) continue;
            
            int c=1;
            int x=a[i];
            while(mp.find(x-1)!=mp.end() && mp[x-1]==false){
                c++;
                x--;
                mp.erase(x);
            }
            ans=max(ans,c);
        }
        return ans; */
        
        unordered_map<int,bool> :: iterator it;
        int ans=1;
        for(it=mp.begin();it!=mp.end();it++){
            int x=it->first;
            
            if(mp[x]==false) continue;
            
            int c=1;
            
            while(mp.find(x-1)!=mp.end() && mp[x-1]==false){
                c++;
                x--;
                mp.erase(x);
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
