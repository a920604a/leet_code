// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <math.h>

bool isPowerBy2(int n)
{
    return (n > 0 && (n & (n - 1))) == 0;
}
int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)

    // if(isPowerBy2(N)){
    //     return log2(N)-1;
    // }
    int count = int(log2(double(N))) + 1;
    int idx = count - 1;
    int ret = 0;
    for (int i = count; i > -1; i--)
    {
        int d = pow(2, idx);
        if (N % d == 0)
        {
            return idx;
            // ret = max(ret, i);
        }
        idx--;
    }
    return ret;
}