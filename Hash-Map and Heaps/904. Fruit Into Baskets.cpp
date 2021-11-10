Question Link: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    
    int atMostkDistinct(vector<int> &a, int k){
        int n=a.size();
        
        map<int,int> mp;
        int i=-1, j=-1;
        int maxlen=0;
        
        while(1){
            bool f1=false, f2=false;
            
            while(j<n-1 && mp.size()<=k){
                f1=true;
                j++;
                
                int x=a[j];
                mp[x]++;
                if(mp.size()<=k){
                    int len=j-i;
                    maxlen=max(maxlen,len);
                }
            }
            
            while(i<j && mp.size()>k){
                f2=true;
                i++;
                
                int x=a[i];
                if(--mp[x]==0) mp.erase(x);
            }
            
            if(f1==false && f2==false) break;
        }
        return maxlen;
    }
    
    int totalFruit(vector<int>& a) {
        int ans=atMostkDistinct(a,2); // maximum length subarray with at most 2 distinct elements
        return ans;
    }
};
