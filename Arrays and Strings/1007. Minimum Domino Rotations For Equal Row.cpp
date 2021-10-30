class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int n=top.size();
        
        int a=top[0], b=bottom[0];
        
        int c1=0, c2=0, c3=0, c4=0;
        for(int i=0;i<n;i++){
            
            // making top array as a
            if(top[i]==a){
                //
            }else if(bottom[i]==a){
                if(c1!=INT_MAX) c1++;
            }else{
                c1=INT_MAX;
            }
            
            // making top array as b
            if(top[i]==b){
                //
            }else if(bottom[i]==b){
                if(c2!=INT_MAX) c2++;
            }else{
                c2=INT_MAX;
            }
            
            // making bottom array as a
            if(bottom[i]==a){
                //
            }else if(top[i]==a){
                if(c3!=INT_MAX) c3++;
            }else{
                c3=INT_MAX;
            }
            
            // making top array as b
            if(bottom[i]==b){
                //
            }else if(top[i]==b){
                if(c4!=INT_MAX) c4++;
            }else{
                c4=INT_MAX;
            }
        }
        int ans=INT_MAX;
        if(c1!=INT_MAX) ans=min(ans,c1);
        if(c2!=INT_MAX) ans=min(ans,c2);
        if(c3!=INT_MAX) ans=min(ans,c3);
        if(c4!=INT_MAX) ans=min(ans,c4);
        
        return (ans==INT_MAX ? -1:ans);
    }
};
