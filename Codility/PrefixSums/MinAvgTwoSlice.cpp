// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // option 1 time out
    int n = A.size();
    if (n == 2)
        return 0;

    vector<float> preSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        preSum[i + 1] = preSum[i] + A[i];
    }
    int ret = -1;
    float val = 1e+4;
    for (int i = 0; i <= n - 2; ++i)
    {
        float avg = (preSum[i + 2] - preSum[i]) / 2;
        for (int j = i + 2; j <= n; ++j)
        {
            float total = preSum[j] - preSum[i];
            avg = min(total / (j - i), avg);
        }
        if (avg < val)
        {
            val = avg;
            ret = i;
        }
    }
    return ret;

    // option 2 最小區間只會存在於兩個是做或是三個數字，因為如果有超過3個數字，代表還可以在拆分
    // O(n) time
    int n = A.size();
    double mn = 100000;
    int idx = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        if ((double)(A[i] + A[i + 1]) / 2.0 < mn)
        {
            mn = (double)(A[i] + A[i + 1]) / 2.0;
            idx = i;
        }
        if (i < n - 2 && (double)(A[i] + A[i + 1] + A[i + 2]) / 3.0 < mn)
        {
            mn = (double)(A[i] + A[i + 1] + A[i + 2]) / 3.0;
            idx = i;
        }
    }

    return idx;
}
