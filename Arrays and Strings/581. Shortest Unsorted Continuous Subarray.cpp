Question Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Approach 1:

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        vector<int> v=a;
        sort(a.begin(),a.end());
        int idx1=-1, idx2=-1;
        for(int i=0;i<n;i++){
            if(v[i]!=a[i]){
                if(idx1==-1){
                    idx1=i;
                }else{
                    idx2=i;
                }
            }
        }
        return (idx1==-1 ? 0:idx2-idx1+1);
    }
};

// Approach 2:

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        
        int curmax=a[0];
        int l=-1, r=-1;
        for(int i=1;i<n;i++){
            if(a[i]<curmax){
                r=i;
            }else{
                curmax=a[i];
            }
        }
        int curmin=a[n-1];
        if(r!=-1){
            for(int i=n-2;i>=0;i--){
                if(a[i]>curmin){
                    l=i;
                }else{
                    curmin=a[i];
                }
            }
        }
        return (r==-1 ? 0:r-l+1);
    }
};
