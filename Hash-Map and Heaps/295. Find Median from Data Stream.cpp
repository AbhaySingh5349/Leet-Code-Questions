Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class MedianFinder {
public:
    
    vector<int> v;
    
    MedianFinder() {
        v.clear();
    }
    
    void addNum(int num) {
        v.push_back(num);
        
        int j=v.size()-1;
        while(j>0 && v[j]<v[j-1]){
			swap(v[j],v[j-1]);
			j--;
		}
    }
    
    double findMedian() {
        double ans=0;
        int n=v.size();
        
        int m=(n-1)/2;
        if(n%2){
            ans=v[m];
        }else{
            ans = (v[m]+v[m+1])/2.0;
        }
        return ans;
    }
};
