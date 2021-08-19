// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(N**2) time
    sort(A.begin(), A.end());
    int ret = 0;
    int n = A.size();
    vector<vector<int> > v;
    for (int i = 0; i < n - 2; ++i)
    {
        int j = i + 1, k = i + 2;

        while (k < n)
        {
            if (A[i] + A[j] > A[k])
            {
                ret += k - j;
                k++;
            }
            else if (j < k - 1)
                j++;
            else
            {
                j++;
                k++;
            }
        }
    }
    return ret;
}