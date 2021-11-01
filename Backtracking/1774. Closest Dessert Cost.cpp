class Solution {
public:
    
    // O(n*3^n)
    
    void solve(vector<int> &toppings, int idx, int &ans, int cost, int target){
        int n=toppings.size();
        
        if(cost==target){
            ans=cost;
            return;
        }
        
        if(abs(cost-target)<abs(ans-target) || (abs(cost-target)==abs(ans-target) && cost<ans)) ans=cost;
        
        if(cost>target) return;
        if(idx==n) return;
        
        for(int i=0;i<3;i++) solve(toppings,idx+1,ans,cost+toppings[idx]*i,target);
    }
    
    int closestCost(vector<int>& base, vector<int>& toppings, int target) {
        int n=base.size();
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            solve(toppings,0,ans,base[i],target);
            if(ans==target) return ans;
        }
        
        return ans;
    }
};
