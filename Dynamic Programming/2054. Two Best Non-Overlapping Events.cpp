Question Link: https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int search(vector<vector<int>>& a, int idx){
        int s=0, e=idx-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(a[m][1]<a[idx][0]){
                if(a[m+1][1]<a[idx][0]){
                    s=m+1;
                }else{
                    return m;
                }
            }else{
                e=m-1;
            }
        }
        return -1;
    }
    
    int maxTwoEvents(vector<vector<int>>& a) {
        int n=a.size();
        
        sort(a.begin(),a.end(),compare);
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,a[i][2]); // considering only single event 
        }
        
        int dp[n]; // maximum profit that can be earned till ith index considering 1 event
        dp[0]=a[0][2];
        for(int i=1;i<n;i++){
            dp[i]=a[i][2];
            int idx=search(a,i);
            
            if(idx!=-1){
                ans=max(ans,dp[i]+dp[idx]);
                dp[i]=max(dp[i],dp[idx]);
            }
            dp[i]=max(dp[i],dp[i-1]);
        }
        return ans;
    }
};
