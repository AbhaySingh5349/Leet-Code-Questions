Question Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Approach 1:

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size();
        
        map<int,int> mp;
        int sum=0;
        int ans=0;
        
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=a[i];
            
            int cur=sum;
            while(cur<0) cur+=k;
            
            int r=(cur)%k;
            if(mp.find(r)!=mp.end()){
                ans+=mp[r];
            }
            mp[r]++;
        } 
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size();
        
        map<int,int> mp;
        int sum=0;
        int ans=0;
        
        mp[0]=1;
        
        for(int i=0;i<n;i++){
            sum+=a[i];
            
            int r=sum%k;
            if(r<0) r+=k;
            if(mp.find(r)!=mp.end()){
                ans+=mp[r];
            }
            mp[r]++;
        }
        return ans;
    }
};
