// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time
    int count = 0;
    if (K == 1)
        return B - A + 1;
    if (A == B)
        return A % K == 0 ? 1 : 0;

    int l = A;
    while (l <= B)
    {
        if (l % K == 0)
        {
            if ((B - l) % K == 0)
                count = (B - l) / K + 1;
            else
                count = (B - l) / K + 1;
            break;
        }
        else
        {
            l++;
        }
    }
    return count;
}
