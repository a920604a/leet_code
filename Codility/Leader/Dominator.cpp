// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    bool first = true;
    int count = -1;
    int val = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (first)
        {
            count = 1;
            val = A[i];
            first = false;
        }
        else
        {
            if (val != A[i])
            {
                count--;
                if (count == 0)
                {
                    count = 1;
                    val = A[i];
                }
            }
            else
                count++;
        }
    }
    count = 0;
    int idx = -1;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == val)
        {
            count++;
            idx = i;
        }
    }
    if (count > int(A.size() / 2))
        return idx;
    return -1;
}