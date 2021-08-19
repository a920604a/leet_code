// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <stack>
int solution(vector<int> &A, vector<int> &B)
{
    // write your code in C++14 (g++ 6.2.0)

    stack<int> sta;
    int eat = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (B[i] == 1)
            sta.push(A[i]);
        else
        {
            if (!sta.empty() && sta.top() < A[i])
            {
                while (!sta.empty() && sta.top() < A[i])
                {
                    // 反方向的魚被吃
                    eat++;
                    sta.pop();
                }
            }
            if (!sta.empty() && sta.top() > A[i])
            {
                // 正方向魚被吃
                eat++;
            }
        }
    }
    return A.size() - eat;
}
