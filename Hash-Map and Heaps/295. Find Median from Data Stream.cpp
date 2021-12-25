Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Approach 1:

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

// Approach 2:

class MedianFinder {
public:
    
    priority_queue<int> maxpq; // left half
    priority_queue<int,vector<int>,greater<int>> minpq; // right half
    
    MedianFinder() {
        maxpq = priority_queue<int>();
        minpq = priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
        int n=maxpq.size(), m=minpq.size();
        
        if(n==0){ // 1st element
            maxpq.push(num);
        }else if(n==m){
            if(num < minpq.top()){
                maxpq.push(num);
            }else{
                int top=minpq.top();
                minpq.pop();
                
                minpq.push(num);
                maxpq.push(top);
            }
        }else if(n==m+1){
            if(m==0){
                if(num>maxpq.top()){
                    minpq.push(num);
                }else{
                    int top=maxpq.top();
                    maxpq.pop();

                    maxpq.push(num);
                    minpq.push(top);
                }
            }else if(num<=maxpq.top()){
                int top=maxpq.top();
                maxpq.pop();
                
                maxpq.push(num);
                minpq.push(top);
            }else{
                minpq.push(num);
            }
        }
    }
    
    double findMedian() {
        double ans=0;
        
        int n=maxpq.size(), m=minpq.size();
        if(n==m){
            ans = (minpq.top() + maxpq.top())/2.0;
        }else{
            ans=maxpq.top();
        }
        return ans;
    }
};
