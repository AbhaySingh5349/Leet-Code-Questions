class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n=a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            int val=it->first, f=it->second;
            if(pq.size()<k){
                pq.push({f,val});
            }else if(pq.size()==k){
                if(pq.top().first < f){
                    pq.pop();
                    pq.push({f,val});
                }
            }
        }
        
        vector<int> ans;
        while(pq.size()>0){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
