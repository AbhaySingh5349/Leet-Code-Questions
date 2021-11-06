class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int> &coins, int amount, int idx){
        int n=coins.size();
        
        if(amount==0) return 0;
        if(idx==n || amount<0) return INT_MAX/2;
        
        if(memo[idx][amount]!=-1) return memo[idx][amount];
        
        int ans=INT_MAX/2;
        
        ans=min(ans,1+solve(coins,amount-coins[idx],idx));
        ans=min(ans,solve(coins,amount,idx+1));
        
        return memo[idx][amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        memo.resize(n,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,0);
        return (ans==INT_MAX/2 ? -1:ans); 
    }
};
