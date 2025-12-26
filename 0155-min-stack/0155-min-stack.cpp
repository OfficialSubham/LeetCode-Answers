class MinStack {
public:
    stack<pair<int, int>> myStack;
    MinStack() {
        
    }
    
    void push(int val) {
        int mini = getMin();
        if(myStack.empty() || val < mini) {
            mini = val;
        }
        myStack.push({val, mini});
    }
    
    void pop() {
        myStack.pop();
    }
    
    int top() {
        return myStack.top().first;
    }
    
    int getMin() {
        return myStack.empty() ? -1 : myStack.top().second;
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