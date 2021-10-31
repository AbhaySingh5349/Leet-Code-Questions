class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
    /*    sort(a.begin(),a.end());
        int n=a.size();
        int i=0, j=n-1;
        int c=0;
        while(i<=j){
            c++;
            int heavy=a[j];
            j--;
            
            int lite=a[i];
            if(limit>=heavy+lite){
                i++;
            }
        }
        return c; */
        int n=a.size();
        int bucket[limit+1];
        for(int i=0;i<limit+1;i++) bucket[i]=0;
        
        for(int i=0;i<n;i++){
            bucket[a[i]]++;
        }
        
        int i=0, j=limit, c=0;
        while(i<=j){
            while(i<=j && bucket[j]==0) j--;
            while(i<=j && bucket[i]==0) i++;
            
            if(i>j || (bucket[i]==0 && bucket[j]==0)) break;
            
            c++;
            
            if((i+j<=limit) && bucket[i]>0){
                bucket[i]--;
            }
            
            if(bucket[j]>0) bucket[j]--;
        }
        return c;
    }
};
