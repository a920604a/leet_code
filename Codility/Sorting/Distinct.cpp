// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_set>
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // option 1
    // O(n) time and O(n) space
    unordered_set<int> s;
    for (int a : A)
        s.insert(a);
    return s.size();
}
