// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
#include <algorithm>
string solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)

    stack<char> sta;
    for (char c : S)
    {
        if (!sta.empty() && sta.top() == c)
        {
            sta.pop();
        }
        else
        {
            sta.push(c);
        }
    }
    string ret;
    while (!sta.empty())
    {
        ret += sta.top();
        sta.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}