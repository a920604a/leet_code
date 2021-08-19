// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // O(N) or O(N*log(N))

    set<int> s;
    for(int a:A){
        s.insert(abs(a));
    }
    return s.size();
}