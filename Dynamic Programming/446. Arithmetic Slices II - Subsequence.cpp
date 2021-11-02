class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n<3) return 0;
        
        map<int,int> mp[n];
        int c=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long int cd=(long)a[i]-a[j];
                
                if (cd < INT_MIN || cd > INT_MAX) continue;
                
                if(mp[j].find(cd)!=mp[j].end()){
                    c+=mp[j][cd];
                    mp[i][cd]+=mp[j][cd]+1;
                }else{
                    mp[i][cd]+=1;
                }
            }
        } 
        return c;
    }
};
