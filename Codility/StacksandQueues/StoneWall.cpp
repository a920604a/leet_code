// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
int solution(vector<int> &H)
{
    // write your code in C++14 (g++ 6.2.0)
    stack<int> sta;
    // monotonic stack
    int ret = 0;
    for (int h : H)
    {
        while (!sta.empty() && sta.top() > h)
        {
            sta.pop();
            ret++;
        }
        if (sta.empty() || h > sta.top())
            sta.push(h);
    }
    return ret + sta.size();
}