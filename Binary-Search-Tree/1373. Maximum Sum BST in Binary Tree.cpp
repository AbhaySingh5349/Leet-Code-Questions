

1.For tree rooted at particular node to be BST:
--> Left Child is BST
--> Right Child is BST
2.Current node has to be BST itself:
--> node value > max value in Left Child
--> node value < min value in Right Child

class Solution {
public:
    
    struct pair{
        bool bst;
        int maxsum; // max sum possible till current root
        int sum,  minVal, maxVal; // current subtree info
        pair(bool check, int ms, int s, int min, int max){
            bst=check;
            maxsum=ms;
            sum=s;
            minVal=min;
            maxVal=max;
        }
    };
    
    struct pair solve(TreeNode* root){
        struct pair p={true,INT_MIN,0,INT_MAX,INT_MIN};
        if(root==NULL) return p;
        
        struct pair lp=solve(root->left);
        struct pair rp=solve(root->right);
        
        int val=root->val;
        
        bool isBST = (val > lp.maxVal && val < rp.minVal && lp.bst && rp.bst); // check if current node form BST
        
        int curMaxSum, curSum, curMin, curMax;
        if(isBST){
            curSum = lp.sum+rp.sum+val;
            curMaxSum = max(curSum,max(lp.maxsum,rp.maxsum));
            curMin = min(val,lp.minVal);
            curMax = max(val,rp.maxVal);
        }else{
            curSum=0;
            curMaxSum=max(lp.maxsum,rp.maxsum);
            curMin=INT_MIN;
            curMax=INT_MAX;
        }
        struct pair cur={isBST,curMaxSum,curSum,curMin,curMax};
        return cur;
    }
    
    int maxSumBST(TreeNode* root) {
        return max(0,solve(root).maxsum);
    }
};
