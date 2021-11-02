Question Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n=a.size();
        int len=0;
        
        // considering each index as starting point of sequence
        
        for(int i=0;i<n-1;i++){
            int prev=a[i];
            int c=1;
            for(int j=i+1;j<n;j++){
                if(a[j]==prev+d){
                    c++;
                    prev=a[j];
                }
            }
            len=max(len,c);
        }
        return len; 
    }
};

// Approach 2:

class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n=a.size();
        int len=0;
        
        // dp[i]: longest subsequence including ith element as last: dp[i]=1+dp[i-d];
        
        map<int,int> m;
        
        for(int i=0;i<n;i++){
            if(m.find(a[i]-d)!=m.end()){
                m[a[i]]=1+m[a[i]-d];
            }else{
                m[a[i]]=1;
            }
            len=max(len,m[a[i]]);
        } 
        
        return len; 
    }
};
