// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // O(N * log(N))

    sort(A.begin(), A.end());
    int n = A.size();
    int l =0 , r = n-1;
    //  -3  1   4
    //  1   

    //  -10 -8  3   4   5
    //  5   3
    int ret = 2e+9;
    while(l<=r){

        ret =min(ret, abs(A[l]+A[r]));
        if(abs(A[l]) > abs(A[r])) l++;
        else r--;

    }

    return ret;
}