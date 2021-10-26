Question Link: https://leetcode.com/problems/min-stack/

// Approach 1:

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

// Approach 2:

class MinStack {
public:
    stack<int> st, minst;
    
    MinStack() {
  
    }
    
    void push(int val) {
        st.push(val);
        if(minst.size()==0 || val<=getMin()) minst.push(val);
    }
    
    void pop() {
        if(st.top()==minst.top()) minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

// Approach 3:

class MinStack {
public:
    
    #define ll long long
    
    stack<ll int> st;
    ll int minval;
    
    MinStack() {
        minval=10000000000;
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            minval=val;
        }else if(val>=minval){
            st.push(val);
        }else{
            ll int dummy=val+(val-minval); // this value will be smaller than current min, detedction point that min val changes
            st.push(dummy);
            minval=val;
        }
    }
    
    void pop() {
        if(st.top()>=minval){
            st.pop();
        }else{
            minval=minval + (minval-st.top());
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=minval){
            return st.top();
        }
        return (int)minval;
    }
    
    int getMin() {
        return (int)minval;
    }
};
