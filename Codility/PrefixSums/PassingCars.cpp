// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    //  0   1   0   1   1
    // (0,1) (0,3) (0,4) (2,3) (2,4)

    // brute force O(n^2) => time out
    // int n = A.size();
    // int count = 0;
    // int l = 0;
    // while (A[l] == 1)
    //     l++;
    // for (int i = l; i < n - 1; ++i)
    // {
    //     if (A[i] == 1)
    //         continue;

    //     for (int j = i + 1; j < n; ++j)
    //         count += A[j];
    // }
    // return count;

    // option 2 O(n) time

    vector<int> vec(n, 0);
    int c = 0;
    for (int i = n - 2; i > -1; i--)
    {
        c += A[i + 1];
        vec[i] = c;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == 0)
        {

            count += vec[i];
            if (count > 1e+9)
                return -1;
        }
    }
    return count;
}
