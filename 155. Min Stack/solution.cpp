class MinStack {
    stack<int>sk;
    stack<int>minsk;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        sk.push(val);
        if (minsk.empty() || val <= minsk.top()) {
            minsk.push(val);
        }
    }

    void pop() {
        if (sk.top() == minsk.top())minsk.pop();
        sk.pop();
    }

    int top() {
        return sk.top();
    }

    int getMin() {
        return minsk.top();
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