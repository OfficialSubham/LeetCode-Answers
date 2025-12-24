class MyStack {
public:
    queue<int> firstQueue;
    MyStack() {
    }
    
    void push(int x) {
        firstQueue.push(x);
        if(firstQueue.empty()) return;
        for(int i = 0; i < firstQueue.size() - 1; i++) {
            int num = firstQueue.front();
            firstQueue.pop();
            firstQueue.push(num);
        }
    }
    
    int pop() {
        int num = firstQueue.front();
        firstQueue.pop();
        return num;
    }
    
    int top() {
        return firstQueue.front();
    }
    
    bool empty() {
        return firstQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */