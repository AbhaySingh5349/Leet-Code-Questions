class Solution {
public:
    int minSetSize(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])!=mp.end()){
                pq.push({mp[a[i]],a[i]});
                mp.erase(a[i]);
            }
        }
        
        int c=0, size=n;
        while(pq.size()>0 && size>n/2){
            int f=pq.top().first, val=pq.top().second;
            pq.pop();
            size-=f;
            c++;
        } 
        return c;
    }
};
