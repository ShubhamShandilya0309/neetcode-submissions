class MinStack {
    stack<int>st;
    stack<int>min_st;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(min_st.empty() || val <= min_st.top()){
            min_st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()==min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
    }
    
    int getMin() {
        if(min_st.empty())return -1;
        return min_st.top();
    }
};
