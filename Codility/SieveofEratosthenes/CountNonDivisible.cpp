// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
vector<int> solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    // O(n^2) => time out

    vector<int> ret;

    for (int i = 0; i < A.size(); ++i)
    {
        // int k = A[i];
        int factor = 0;
        for (int j = 0; j < A.size(); ++j)
        {
            if (A[i] % A[j] != 0)
                factor++;
        }

        ret.push_back(factor);
    }
    return ret;
}