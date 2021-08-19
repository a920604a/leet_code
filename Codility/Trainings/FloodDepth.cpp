// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // 42. Trapping Rain Water

    // O(n) time and O(n) space for

    //      1   3   2   1   2   1   5   3   3   4   2
    //l     1   3   3   3   3   3   5   5   5   5   5
    //r     5   5   5   5   5   5   5   4   4   4   2
    //      0   0   1   2   1   2   0   1   1   0   0
    int n = A.size();
    vector<int> l_max(n, 0), r_max(n, 0);
    l_max[0] = A[0], r_max[n - 1] = A[n - 1];
    for (int i = 1; i < n; ++i)
    {
        l_max[i] = max(l_max[i - 1], A[i]);
    }
    for (int i = n - 2; i > -1; i--)
    {
        r_max[i] = max(r_max[i + 1], A[i]);
    }

    int ret = 0;

    for (int i = 0; i < n; ++i)
    {
        ret = max(min(l_max[i], r_max[i]) - A[i], ret);
    }
    return ret;
}
