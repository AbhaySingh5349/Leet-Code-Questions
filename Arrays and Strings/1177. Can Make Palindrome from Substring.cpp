Question Link: https://leetcode.com/problems/can-make-palindrome-from-substring/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<bool> ans(n,false);
        
        for(int k=0;k<n;k++){
            int i=queries[k][0], j=queries[k][1], allowed=queries[k][2];
            
            vector<int> freq(26,0);
            for(int idx=i;idx<=j;idx++) freq[s[idx]-'a']++;
            
            int odd=0;
            for(int idx=0;idx<26;idx++) odd += (freq[idx]%2 != 0);
            
            ans[k] = (odd/2<=allowed);
        } 
        
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<bool> ans(n,false);
        
        vector<vector<int>> dp;
        vector<int> freq(26,0);
        
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            dp.push_back(freq);
        }
        
        for(int k=0;k<n;k++){
            int i=queries[k][0], j=queries[k][1], allowed=queries[k][2];
            
            vector<int> low(26,0), high(26,0);
            
            if(i>0) low=dp[i-1];
            high=dp[j]; 
            
            int odd=0;
            for(int idx=0;idx<26;idx++){
                int f=high[idx]-low[idx];
                odd += (f%2 != 0);
            }
            
            ans[k] = (odd/2<=allowed);
        }
        
        return ans;
    }
};
