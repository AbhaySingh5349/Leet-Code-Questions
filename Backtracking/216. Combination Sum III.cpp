Question Link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    
    void ksum(vector<int> &a, int k, int n, int idx, int target, vector<vector<int>> &ans, vector<int> &sub){
        if(target<0 || n-idx<k) return;
        if(k==0){
            if(target==0) ans.push_back(sub);
            return;
        }
        
        while(idx<n){
            sub.push_back(a[idx]);
            ksum(a,k-1,n,idx+1,target-a[idx],ans,sub);
            sub.pop_back();
            idx++;
            while(idx<n && a[idx]==a[idx-1]) idx++;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        for(int i=0;i<9;i++) a.push_back(i+1);
        
        vector<vector<int>> ans;
        vector<int> sub;
        ksum(a,k,9,0,n,ans,sub);
        
        return ans;
    }
};
