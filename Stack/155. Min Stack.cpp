class MinStack {
public:
    stack<int> st;
    
    MinStack() {
  
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> minst;
        
        int minval=INT_MAX;
        while(st.size()>0){
            minval=min(minval,st.top());
            minst.push(st.top());
            st.pop();
        }
        while(minst.size()>0){
            int val=minst.top();
            minst.pop();
            st.push(val);
        }
        
        return minval;
    }
};
