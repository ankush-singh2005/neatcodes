class MinStack {
public:
    
    stack<pair<int,int>> st;
    MinStack() {
        stack<pair<int,int>> st;
    }
    
    void push(int val) {
       if(st.empty()) st.push({val,val});
       else{
        st.push({val,min(val,st.top().second)});
       }
    }
    
    void pop() {
        if(st.empty()) return;
        else st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        else return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */