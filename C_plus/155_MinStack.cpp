/*
 * @Author: yuan
 * @Date: 2021-04-29 14:24:47
 * @LastEditTime: 2021-04-29 14:24:47
 * @FilePath: /C_plus/155_MinStack.cpp
 */
class MinStack
{
public:
    /** initialize your data structure here. */

    stack<int> sta;
    stack<int> min;
    MinStack()
    {
    }

    void push(int val)
    {
        sta.push(val);
        if (min.empty() || val <= min.top())
            min.push(val);
    }

    void pop()
    {
        if (sta.top() == min.top())
            min.pop();
        sta.pop();
    }

    int top()
    {
        return sta.top();
    }

    int getMin()
    {
        return min.top();
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