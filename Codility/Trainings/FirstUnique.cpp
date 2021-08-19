// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <unordered_map>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(NlogN) time and O(n) space
    unordered_map<int, int> mp;

    int n = A.size();
    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        mp[A[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (mp[A[i]] == 1)
            return A[i];
    }
    return ans;
}
