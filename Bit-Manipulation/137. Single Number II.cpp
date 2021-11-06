class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n=a.size();
        
        vector<int> count(32,0);
        for(int i=0;i<n;i++){
            int x=a[i];
            for(int j=0;j<32;j++){
                if(x&(1<<j)){
                    count[j]++; // storing count of set bits at each position
                }
            }
        }
        
        // as most numbers are occuring 3 times, so count of set bits must be multiple of 3, else extra bit is contributed by number occuring once
        int num=0;
        int p=1;
        for(int j=0;j<32;j++){
            if(count[j]%3==1){
                num |= (1<<j);
            }
        }
        return num;
    }
};
