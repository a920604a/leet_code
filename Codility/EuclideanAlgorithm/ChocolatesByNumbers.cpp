// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int gcd(int a, int b){
    if(a%b==0) return b;
    else return gcd(b, a%b);
}

int solution(int N, int M)
{
    // write your code in C++14 (g++ 6.2.0)
    // option 1 O(n) time out
    int ret = 0;
    vector<bool> eaten(N, false);
    for (int i = 0; i < N; i = (i + M) % N)
    {

        if (!eaten[i])
        {
            eaten[i] = true;
            ret++;
        }
        else
            break;
    }
    return ret;

    // option 2 O(log(N + M))  time
    return N/gcd(N,M);
}
