class Solution {
public:
    
    int solve(vector<string>& words, int idx, vector<int> &freq, vector<int> &score){
        int n=words.size();
        if(idx==n) return 0;
        
        int sub1=0, sub2=0;
        
        // not include
        sub1=solve(words,idx+1,freq,score);
        
        // include
        bool possible=true;
        string s=words[idx];
        int cur=0;
        for(int i=0;i<s.length();i++){
            int j=s[i]-'a';
            if(freq[j]==0) possible=false;
            cur+=score[j];
            freq[j]--;
        }
        if(possible) sub2=cur+solve(words,idx+1,freq,score);
        
        for(int i=0;i<s.length();i++){
            int j=s[i]-'a';
            freq[j]++;
        }
        
        return max(sub1,sub2);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(int i=0;i<letters.size();i++){
            int idx=letters[i]-'a';
            freq[idx]++;
        }
        
        return solve(words,0,freq,score);
    }
};
