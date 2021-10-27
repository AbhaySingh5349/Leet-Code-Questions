Question Link: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& a) {
        sort(a.begin(),a.end());
        
        int maxreach=0;
        int i=0;
        while(i<a.size()){
            if(a[i]<=maxreach+1){
                maxreach+=a[i];
                i++;
            }else{
                break;
            }
        }
        return maxreach+1;
    }
};
