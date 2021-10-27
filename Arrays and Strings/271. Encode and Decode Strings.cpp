class Solution {
public:
  
    string encode(vector<string> &v) {
        string s="";
        for(int i=0;i<v.size();i++){
            int len=v[i].length();
            s+=to_string(len)+"$"+v[i];
        }
        return s;
    }

    vector<string> decode(string &s) {
        vector<string> v;
        int n=s.length();
        int i=0;
        while(i<n){
            int len=0;
            while(i<n && s[i]!='$'){
                len=len*10+(s[i]-'0');
                i++;
            }
            i++;
            string cur="";
            while(i<n && len!=0){
                cur+=s[i];
                i++;
                len--;
            }
            v.push_back(cur);
        }
        return v;
    }
};
