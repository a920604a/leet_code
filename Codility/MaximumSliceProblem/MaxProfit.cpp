// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(1) space
    int mn = 400000, ret = 0;
    for(int i=0;i<A.size();++i){
        
        mn = min(A[i], mn);
        ret = max(ret, A[i] - mn);
    }
    return ret;
}
