// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    //  3   2   -6  4   0

    int local_max = 0, global_max = -1e+6;
    for (int i = 0; i < A.size(); ++i)
    {
        local_max = max(local_max + A[i], A[i]);
        if (global_max < local_max)
        {
            global_max = local_max;
        }
    }
    return global_max;
}
