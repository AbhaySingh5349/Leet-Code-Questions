class Solution {
public:
    
    #define ll long long
    int mod=1e9+7;
    
    struct person{
        int eff;
        int sp;
    };
    
    struct pqcompare{
        bool operator()(const person &a, const person &b){
            return a.sp > b.sp; // min heap
        }
    };
    
    static bool compare(person &a, person &b){
        return a.eff > b.eff;
    }
    
    ll int getMax(ll int a, ll int b){
        if(a>=b) return a;
        return b;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<person> v;
        for(int i=0;i<n;i++){
            struct person p={efficiency[i],speed[i]};
            v.push_back(p);
        }
        sort(v.begin(),v.end(),compare);
        
        ll int sum=0, ans=0;
        priority_queue<person,vector<person>,pqcompare> pq;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                sum-=pq.top().sp;
                pq.pop();
            }
            sum+=v[i].sp;
            pq.push(v[i]);
            ans = getMax(ans,sum*v[i].eff);
        }
        
        return (int)(ans%mod);
    }
};
