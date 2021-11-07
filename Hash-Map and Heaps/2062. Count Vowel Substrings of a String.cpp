Question Link: https://leetcode.com/problems/count-vowel-substrings-of-a-string/

class Solution {
public:
    
    bool isValid(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    
    int count(string s, int k){
        int n=s.length();
        map<char,int> mp;
        int i=0, j=0;
        int ans=0;
        while(j<n){
            char ch=s[j];
            if(!isValid(ch)){
                mp.clear();
                i=j+1;
            }else{
                mp[ch]++;
                while(mp.size()>k){
                    ch=s[i];
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                    i++;
                }
                ans+=(j-i+1); // count of substrings with at most K vowels
                }
            j++;
        }
        return ans; 
    }
    
    int countVowelSubstrings(string s) {
        int n=s.length();
        if(n<5) return 0;
        
        return (count(s,5)-count(s,4));
    }
};
