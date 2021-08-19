// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    int n = A.size();
    vector<int> l_max(n, 0), r_max(n, 0);
    //    3   2   6   -1  4   5   -1  2
    //l   0   2   8    7  11  16  15   0
    //r   0  16   14   8   9   5   0   0

    for (int i = 1; i < n - 1; ++i)
    {
        l_max[i] = max(l_max[i - 1] + A[i], 0);
    }
    for (int i = n - 2; i > 0; i--)
    {
        r_max[i] = max(r_max[i + 1] + A[i], 0);
    }
    int mx = 0;

    for (int i = 1; i < n - 1; i++)
    {
        mx = max(mx, l_max[i - 1] + r_max[i + 1]);
    }
    return mx;
}
