class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        s1+=' ';
        s2+=' ';
        int n=s1.length(), m=s2.length();
        if(n==m && s1==s2) return true;
        
        deque<string> a,b;
        
        string temp="";
        for(int i=0;i<n;i++){
            if(s1[i]==' '){
                a.push_back(temp);
                temp="";
            }else{
                temp+=s1[i];
            }
        }
        
        temp="";
        for(int i=0;i<m;i++){
            if(s2[i]==' '){
                b.push_back(temp);
                temp="";
            }else{
                temp+=s2[i];
            }
        }
        
        while((a.size()>0 && b.size()>0) && (a.front()==b.front())) a.pop_front(), b.pop_front();
        while((a.size()>0 && b.size()>0) && (a.back()==b.back())) a.pop_back(), b.pop_back();
        
        return (a.size()==0 || b.size()==0);
    }
};
