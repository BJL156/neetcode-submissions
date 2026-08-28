class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minSt.empty() || minSt.top() >= val) {
            minSt.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if ((!st.empty() && !minSt.empty()) && st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }

    std::stack<int> st;
    std::stack<int> minSt;
};
