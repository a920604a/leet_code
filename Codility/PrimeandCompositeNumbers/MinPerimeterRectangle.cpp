// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
vector<int> factor(int N)
{

    vector<int> factor;
    int i;
    for (i = 1; i < N / i; ++i)
    {
        if (N % i == 0)
        {
            factor.push_back(i);
        }
    }
    if (i * i == N)
        factor.push_back(i);
    return factor;
}
int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(sqrt(n))
    // 面積為 N，求最小周長組合
    // 先求 30 的因數
    vector<int> vec = factor(N);
    int ret = 1e+9 * 2;
    for (int i : vec)
    {
        int perimeter = 2 * (i + N / i);
        ret = min(ret, perimeter);
    }
    return ret;
}
