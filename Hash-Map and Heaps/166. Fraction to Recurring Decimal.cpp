Question Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int nr, int dr) {
        if(nr==0) return "0";
        
        bool positive=true;
        if(nr<0 && dr<0){
            positive=true;
        }else if(nr<0 || dr<0){
            positive=false;
        }
        
        long n=(long)nr, d=(long)dr;
        if(n<0) n*=-1;
        if(d<0) d*=-1;
        
        string ans=(positive==true ? "":"-");
        ans+=to_string(n/d);
        
        long long int r=n%d;
        if(r!=0){
            ans+=".";
            
            map<int,int> mp;
            int pos=ans.length();
            mp[r]=pos;
            
            while(r){
                r*=10;
                int q=r/d;
                ans+=to_string(q);
                
                r%=d;
                
                if(mp.find(r)!=mp.end()){
                    pos=mp[r];
                    ans.insert(pos,"(");
                    ans+=")";
                    break;
                }
                mp[r]=ans.length();
            }
        }
        return ans;
    }
};
