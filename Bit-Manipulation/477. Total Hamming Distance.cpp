class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        int n=a.size();
        
        int ans=0;
        
    /*    vector<int> count(32,0); // count of set bits 
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                int bit=a[i]&(1<<j);
                if(bit==0){
                    ans+=count[j];
                }else{
                    ans+=((n-1-i)-count[j]);
                    count[j]++;
                }               
            }
        } */
            
        for(int j=0;j<32;j++){
            int count=0;
            for(int i=n-1;i>=0;i--){
                int bit=a[i]&(1<<j);
                if(bit==0){
                    ans+=count;
                }else{
                    ans+=((n-1-i)-count);
                    count++;
                }
            }
        }
        
        return ans;
    }
};
