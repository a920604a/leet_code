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

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] != i + 1)
            return 0;
    }
    return 1;
}