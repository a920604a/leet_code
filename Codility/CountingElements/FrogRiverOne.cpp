// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    //  最短多少秒 可以到達 A
    // A[3] = 4 , 代表 在 3 這位置，葉子掉落時間為 4
    //  1   3   1   4   2   3   5   4
    //
    // O(N)
    set<int> s;
    
    for (int i = 0; i < A.size(); ++i)
    {
        s.insert(A[i]);
        if ((int)s.size() == X)
            return i;
    }
    return -1;
}
