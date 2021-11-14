Question Link: https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
public:
    
    vector<string> v;
    int idx;
    int n;
    
    int setBits(int num){
        int c=0;
        while(num>0){
            int rmsb = (num & (-num));
            num-=rmsb;
            c++;
        }
        return c;
    }
    
    CombinationIterator(string s, int k) {
        int len=s.length();
        int range=(1<<len);
        
        set<string> st;
        for(int i=1;i<range;i++){
            string sub="";
            int c=setBits(i);
            if(c!=k) continue;
            for(int j=0;j<len;j++){
                if((i & (1<<j))) sub+=s[j];
            }
            if(st.find(sub)==st.end()) st.insert(sub);
        }
        if(st.size()>0){
            idx=0;
            v.assign(st.begin(),st.end());
        }else{
            idx=-1;
        }
        n=v.size();
    }
    
    string next() {
        if(idx==-1 || idx==n) return "";
        return v[idx++];
    }
    
    bool hasNext() {
        return (idx>=0 && idx<n);
    }
};
