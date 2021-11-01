class Solution {
public:
    
    struct node{
        double inc; // increase in current average if we add 1 extra student to particular class
        int p;
        int t;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.inc < b.inc; // max heap
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n=classes.size();
        
        priority_queue<node,vector<node>,compare> pq;
        for(int i=0;i<n;i++){
            int p=classes[i][0], t=classes[i][1];
            
            struct node c={double(p+1)/double(t+1) - double(p)/double(t), p,t};
            pq.push(c);
        }
        
        while(extra>0){
            struct node c=pq.top();
            pq.pop();
            
            c.p++, c.t++;
            pq.push({double(c.p+1)/double(c.t+1) - double(c.p)/double(c.t), c.p, c.t});
            
            extra--;
        }
        
        double ans=0;
        while(pq.size()>0){
            struct node c=pq.top();
            pq.pop();
            ans+=double(c.p)/double(c.t);
        }
        return (ans/n);
    }
};
