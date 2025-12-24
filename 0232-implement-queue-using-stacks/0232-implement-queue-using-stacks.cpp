class MyQueue {
private:
    void recursive(int n, stack<int> &myStack) {
        if(myStack.empty()) return myStack.push(n);
        int num = myStack.top();
        myStack.pop();
        recursive(n, myStack);
        myStack.push(num);
    }
public:
    stack<int> myStack;
    MyQueue() {
        
    }
    
    void push(int x) {
        recursive(x, myStack);
    }
    
    int pop() {
        int num = myStack.top();
        myStack.pop();
        return num;
    }
    
    int peek() {
        return myStack.top();
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */