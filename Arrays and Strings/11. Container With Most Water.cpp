class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
    /*    for(int i=0;i<n;i++){
            int h=height[i];
            int idx=i;
            for(int j=i+1;j<n;j++){
                if(height[j]>=h) idx=j;
            }
            ans=max(ans,h*(idx-i));
            
            idx=i;
            for(int j=i-1;j>=0;j--){
                if(height[j]>=h) idx=j;
            }
            ans=max(ans,h*(i-idx)); 
        }
        return ans; */
        int i=0, j=n-1;
        while(i<j){
            int b=j-i;
            int hi=height[i], hj=height[j];
            int h=min(hi,hj);
            
            if(hi<hj){
                i++;
            }else{
                j--;
            }
            
            ans=max(ans,h*b);
        }
        return ans;
    }
};
