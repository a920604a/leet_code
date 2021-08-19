// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) space and O(n) time
    if (A.empty())
        return {};
    int size = A.size();
    vector<int> ret(size, 0);
    int k = K % size;
    for (int i = 0; i < size; ++i)
    {
        int j = (size - k + i) % size;
        ret[i] = A[j];
    }
    return ret;
}
