class Solution {
public:
    
    void remove(unordered_map<int,int> &mp, int val){
        mp[val]--;
        if(mp[val]==0) mp.erase(val);
    }
    
    bool isPossible(vector<int>& a) {
        int n=a.size();
        if(n<3) return false;
        
        unordered_map<int,int> freq, tail;
        for(int i=0;i<n;i++) freq[a[i]]++;
        
        for(int i=0;i<n;i++){
            if(freq.find(a[i])!=freq.end()){
                if(tail.find(a[i]-1)!=tail.end()){ 
                    // we can append current num to previous subsequence
                    tail[a[i]]++;
                    remove(tail,a[i]-1);
                }else if(freq.find(a[i]+1)!=freq.end() && freq.find(a[i]+2)!=freq.end()){
                    // start new subsequence
                    remove(freq,a[i]+1);
                    remove(freq,a[i]+2);
                    tail[a[i]+2]++;
                }else{
                    return false;
                }
                remove(freq,a[i]);
            }
        }
        return true;
    }
};
