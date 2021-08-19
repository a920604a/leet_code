// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int sum(vector<int> &A, int i, int s)
{
    if (i == A.size())
        return s;
    int l = s + A[i];
    int r = s - A[i];
    return min(abs(sum(A, i + 1, l)), abs(sum(A, i + 1, r)));
}

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // option 1 brute force O(2^n)
    sum(A,0,0);

   
}
