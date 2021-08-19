// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // O(nlogn) time
    sort(A.begin(), A.end());
    int n = A.size();

    return max(A[0] * A[1] * A[n - 1], A[n - 3] * A[n - 2] * A[n - 1]);
}
