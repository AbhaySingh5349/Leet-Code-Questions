Question Link: https://leetcode.com/problems/count-the-hidden-sequences/

class Solution {
public:
    int numberOfArrays(vector<int> &a, int low, int high) {
        int n=a.size();
        
        long long int mine=0, maxe=0, sum=0;
        for(int i=0;i<n;i++){
            sum += a[i];
            mine=min(mine,sum);
            maxe=max(maxe,sum);
        }
        long long int ub=high-maxe, lb=low-mine;
        return (ub-lb+1 > 0 ? ub-lb+1:0 );
    }
};
