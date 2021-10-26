class Solution {
public:

// storing index of Next Greater or Equal on Right
vector<int> greaterEqualOnRight(vector<int>& a){
    int n=a.size();
    vector<int> ngr(n,n);
    stack<pair<int,int>> st;
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 && st.top().first<a[i]) st.pop();
        if(st.size()>0){
            ngr[i]=st.top().second;
        }
        st.push({a[i],i});
    }
    return ngr;
}

vector<int> maxSlidingWindow(vector<int>& a, int k) {
    int n=a.size();
    vector<int> ngr=greaterEqualOnRight(a);
    
    int i=0, j=0;
    vector<int> ans;
	// i is starting index of K size window
	// j points at max value in window
    while(i<=n-k){
        j=max(i,j);
        while(ngr[j]<i+k){
            j=ngr[j]; // if index is within k size window for next greater element
        }
        ans.push_back(a[j]);
        i++;
    }
    return ans;
}
};
