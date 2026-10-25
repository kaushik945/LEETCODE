class MinStack {
public:
    stack<long long> s;
    long long mini = INT_MAX;
    MinStack() {}

    void push(long long val) {
        if (s.empty()) {
            mini = val;
            s.push(val);
        } else {
            if (val > mini)
                s.push(val);
            else {
                s.push(2 * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if(s.top() < mini){
            mini = 2*mini - s.top();
            s.pop();
        }
        else s.pop();

    }

    long long top() {
        if(s.top() < mini){
            return mini;
        }
        return s.top();
    }

    long long getMin() {
        return mini;
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