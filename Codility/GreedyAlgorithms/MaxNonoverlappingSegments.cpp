// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A, vector<int> &B)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n)
    if (A.empty())
        return 0;
    int n = A.size();
    int ret = 1;
    int start = A[0], end = B[0];
    for (int i = 1; i < n; ++i)
    {
        if (end < A[i])
        {
            ret++;
            end = B[i];
        }
    }
    return ret;
}