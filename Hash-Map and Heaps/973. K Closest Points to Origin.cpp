Question Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    
    #define ll long long 
    
    struct node{
        double dist;
        int x;
        int y;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.dist < b.dist; // max heap
        }
    };
    
    double distance(ll int x, ll int y){
        double d=sqrtl(x*x + y*y);
        return d;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        
        priority_queue<node,vector<node>,compare> pq;
        for(int i=0;i<n;i++){
            ll int x=points[i][0], y=points[i][1];
            double d=distance(x,y);
            
            if(pq.size()<k){
                pq.push({d,(int)x,(int)y});
            }else if(pq.size()==k){
                if(pq.top().dist > d){
                    pq.pop();
                    pq.push({d,(int)x,(int)y});
                }
            }
        }
        
        vector<vector<int>> ans;
        while(pq.size()>0){
            struct node p=pq.top();
            pq.pop();
            ans.push_back({p.x,p.y});
        }
        return ans;
    }
};
