Question Link: https://leetcode.com/problems/sequential-digits/

// Approach 1:

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int x=low, lb=0;
        while(x>0){
            lb++;
            x/=10;
        }
        
        int y=high, ub=0;
        while(y>0){
            ub++;
            y/=10;
        }
        
        string s="123456789";
        int n=10;
        
        vector<int> ans;
        for(int len=lb;len<=ub;len++){
            for(int i=0;i<n-len;i++){
                int j=i+len-1;
                int val=0;
                for(int k=i;k<=j;k++) val = val*10 + (s[k]-'0');
                
                if(val>=low && val<=high) ans.push_back(val);
            }
        }
        return ans; 
    }
};

// Approach 2:

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1;i<=9;i++) q.push(i);
        
        vector<int> ans;
        while(q.size()>0){
            int num=q.front();
            q.pop();
            
            if(num>high) break;
            
            if(num>=low && num<=high) ans.push_back(num);
            int r=num%10 + 1;
            if(r<10){
                int next=num*10 + r;
                q.push(next);
            }
        }
        return ans;
    }
};
