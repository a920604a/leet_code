class MyQueue
{
private:
    stack<int> sta;
    stack<int> back;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        sta.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (sta.empty())
            return -1;
        int size = sta.size();
        size--;
        while (size)
        {
            int val = sta.top();
            back.push(val);
            sta.pop();
            size--;
        }
        int ret = sta.top();
        sta.pop();
        while (!back.empty())
        {
            int val = back.top();
            back.pop();
            sta.push(val);
        }
        return ret;
    }

    /** Get the front element. */
    int peek()
    {
        int size = sta.size();
        size--;
        while (size)
        {
            int val = sta.top();
            back.push(val);
            sta.pop();
            size--;
        }
        int ret = sta.top();

        while (!back.empty())
        {
            int val = back.top();
            back.pop();
            sta.push(val);
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return sta.empty();
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