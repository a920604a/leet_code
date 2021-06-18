class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> minsta;
    stack<int> sta;

    MinStack()
    {
    }

    void push(int val)
    {
        sta.push(val);
        if (minsta.empty() || val <= minsta.top())
            minsta.push(val);
    }

    void pop()
    {
        int tmp;

        tmp = sta.top();
        sta.pop();

        if (!minsta.empty() && tmp == minsta.top())
            minsta.pop();
    }

    int top()
    {
        return sta.top();
    }

    int getMin()
    {
        return minsta.top();
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