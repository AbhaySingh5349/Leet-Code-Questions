class Solution {
public:
    int numRabbits(vector<int>& a) {
        int n=a.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        int c=0;
        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            int size=it->first+1, f=it->second;
            int grp=(f/size)+(f%size!=0);
            c+=size*grp;
        }
        return c;
    }
};
