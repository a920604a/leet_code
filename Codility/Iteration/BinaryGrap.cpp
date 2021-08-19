// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <algorithm>
int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(n) space
    
    int ret = 0;
    bool flag = false;

    vector<int> vec;
    // to string
    while (N)
    {
        vec.push_back(N & 1);
        N >>= 1;
    }
    reverse(vec.begin(), vec.end());

    int c = 0;
    for (int i : vec)
    {
        if (i == 0)
            c++;
        else
        {
            if (flag)
            {
                ret = max(ret, c);
                c = 0;
            }
            flag = true;
        }
    }

    return ret;
}
