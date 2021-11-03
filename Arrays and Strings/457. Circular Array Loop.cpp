

// Approach 1:

class Solution {
public:
    
    bool circularArrayLoop(vector<int>& a) {
        int n=a.size();
        
        for(int i=0;i<n;i++){
            set<int> visited;
            visited.insert(i);
            
            int j=(i+a[i])%n;
            if(j<0) j+=n;
            
            bool possible=true;
            int len=1;
            
            while(1){
                if(a[i]*a[j]<0){
                    possible=false;
                    break;
                }
                if(visited.find(j)!=visited.end()) break;
                len++;
                visited.insert(j);
                
                int next=(j+a[j])%n;
                if(next<0) next+=n;
                if(next==j){
                    possible=false;
                    break;
                }
                j=next;
            }
            if(possible && len>1) return true;
        }
        return false; 
    }
};

// Approach 2:

class Solution {
public:
    
    int getNextPosition(vector<int> &a, int idx, bool isForward){
        int n=a.size();
        if(a[idx]==0) return -1;
        
        int direction=(a[idx]>0);
        
        if(direction!=isForward) return -1;
        
        int next=(idx+a[idx])%n;
        if(next<0) next+=n;
        
        if(next==idx) return -1;
        
        return next;
    }
    
    void markVisited(vector<int> &a, int idx, bool isForward){
        int n=a.size();
        
        while(1){
            int prev=idx;
            idx=getNextPosition(a,idx,isForward);
            if(idx==-1) break;
            a[prev]=0;
        }
    }
    
    bool circularArrayLoop(vector<int>& a) {
        int n=a.size();
        
        for(int i=0;i<n;i++){
            if(a[i]==0) continue;
            
            bool forward=true;
            if(a[i]<0) forward=false;
            
            int slow=i, fast=i;
            while(1){
                slow=getNextPosition(a,slow,forward);
                if(slow==-1) break;
                
                fast=getNextPosition(a,fast,forward);
                if(fast==-1) break;
                
                fast=getNextPosition(a,fast,forward);
                if(fast==-1) break;
                
                if(slow==fast) return true;
            }
            markVisited(a,i,forward);
        } 
        return false;
    }
};
