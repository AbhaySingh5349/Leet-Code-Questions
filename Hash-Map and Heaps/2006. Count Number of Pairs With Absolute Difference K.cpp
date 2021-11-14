Question Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

// Approach 1:

class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        int n=a.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(a[i]-a[j]);
                if(d==k) c++;
            }
        } 
        
        return c; 
    }
};

// Approach 2:

class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        int n=a.size();
        int c=0;
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x=a[i]+k;
            if(mp.find(x)!=mp.end()) c+=mp[x];
            
            int y=a[i]-k;
            if(mp.find(y)!=mp.end()) c+=mp[y];
            
            mp[a[i]]++;
        }
        
        return c; 
    }
};
