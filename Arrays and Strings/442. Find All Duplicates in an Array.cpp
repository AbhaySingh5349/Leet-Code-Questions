class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size(), i;
        
        vector<int> ans;
        for(i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]<0){
                ans.push_back(idx+1); // or nums[i]
            }else{
                nums[idx]*=-1;
            }
        }
        return ans;
    }
};
