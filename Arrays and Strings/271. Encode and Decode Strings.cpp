Question Link: https://leetcode.com/problems/encode-and-decode-strings/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& v) {
        int n=v.size();
        
        string s="";
        for(int i=0;i<n;i++){
            int len=v[i].length();
            
            s += to_string(len) + "$" + v[i];
        }
        
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> v;
        int n=s.length(), i=0;
        
        while(i<n){
            int len=0;
            while(i<n && isdigit(s[i])) len = len*10 + (s[i++]-'0');
            
            i++;
            string sub="";
            while(len--) sub+=s[i++];
            
            v.push_back(sub);
        }
        
        return v;
    }
};
