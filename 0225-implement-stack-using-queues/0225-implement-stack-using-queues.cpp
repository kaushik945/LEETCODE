class MyStack {
public:
    queue<int> s;

    MyStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        int n = s.size();
        for(int i = 0; i < n-1; i++){
            s.push(s.front());
            s.pop();
        }
    }
    
    int pop() {
        int val = s.front();
        s.pop();
        return val;
    }
    
    int top() {
        return s.front();
    }
    
    bool empty() {
        int n = s.size();
        if(n == 0) return true;
        return false;
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