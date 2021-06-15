/*
 * @Author: yuan
 * @Date: 2021-05-01 18:24:16
 * @LastEditTime: 2021-05-01 18:24:16
 * @FilePath: /C_plus/225_ImplementStackUsingQueue.cpp
 */
class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q.empty())
            return -1;
        int val = q.back();
        int size = q.size() - 1;
        while (size)
        {
            int top = q.front();
            q.push(top);
            q.pop();
            size--;
        }
        q.pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        if (q.empty())
            return -1;
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
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