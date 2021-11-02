class Solution {
public:
    
    int maximumScore(vector<int>& a, int k) {
        int n=a.size();
        
        vector<int> nsr(n,n), nsl(n,-1);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && st.top().first>=a[i]){
                int idx=st.top().second;
                st.pop();
                nsr[idx]=i;
            }
            if(st.size()>0) nsl[i]=st.top().second;
            st.push({a[i],i});
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(nsl[i]<k && nsr[i]>k) ans=max(ans,a[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;
    }
};
