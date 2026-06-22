class MinStack {
public:
    long long min;
    stack<long long>st;
    MinStack() {
        min=LLONG_MAX;
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            st.push(val);
            min=value;
        }
        else if(min>=val){
            st.push(2*val-min);
            min=val;
        }else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long t=st.top();
        st.pop();
        if(min>t){
            min=2*min-t;
        }
    }
    
    int top() {
        long long t=st.top();
        if(min>t){
           return (int)min;
        }else{
            return (int)t;
        }
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */