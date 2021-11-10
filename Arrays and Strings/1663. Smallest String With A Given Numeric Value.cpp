Question Link: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    
    string getSmallestString(int n, int k) {
        string ans = string(n, 'a');
        
        k-=n;
        int idx=n-1;
        while(k>0){
            ans[idx]+=min(25,k);
            k-=min(25,k);
            idx--;
        }

        return ans;
    }
};
