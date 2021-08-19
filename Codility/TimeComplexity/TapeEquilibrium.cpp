// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(n) space
    int n = A.size();
    vector<int> sum(n, 0);
    // 3    1   2   4   3
    // 13   10   9   7   3
    sum[n - 1] = A[n - 1];
    for (int i = n - 2; i > -1; i--)
    {
        sum[i] = sum[i + 1] + A[i];
    }

    int ret = INT_MAX, total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total += A[i];
        ret = min(abs(total - sum[i + 1]), ret);
    }
    return ret;
}
