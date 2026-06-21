class MinStack {
public:
    stack<int> stk;
    stack<int> mins;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        val = std::min(val, mins.empty() ? val : mins.top());
        mins.push(val);
    }
    
    void pop() {
        stk.pop();
        mins.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
