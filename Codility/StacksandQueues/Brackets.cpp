// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
int solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(n) space
    stack<char> sta;
    for (char c : S)
    {

        if (c == '(' || c == '{' || c == '[')
            sta.push(c);

        else
        {
            if (sta.empty())
                return 0;
            else if (c == ')' && sta.top() == '(')
                sta.pop();
            else if (c == ']' && sta.top() == '[')
                sta.pop();
            else if (c == '}' && sta.top() == '{')
                sta.pop();
            else
                return 0;
        }
    }

    return sta.empty()?1:0;
}
