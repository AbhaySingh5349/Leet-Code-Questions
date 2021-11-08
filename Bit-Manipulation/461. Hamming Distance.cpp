class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        for(int i=0;i<32;i++){
            long long int bit=(1<<i);
            if((x&bit)!=(y&bit)) c++;
        }
        return c;
    }
};
