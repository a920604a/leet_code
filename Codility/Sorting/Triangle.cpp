// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    // option 1
    // O(NlogN) time
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0;i<n-2;++i){
        // A[i] + A[i+1] 可能 overflow，所以改成相減
        if( A[i] > A[i+2] -A[i+1]   ){
            // A[i+2] + A[i+2] > A[i] 不用比較，因為排序過了
            // A[i+2] + A[i] > A[i+1] 不用比較，因為排序過了
            return 1;
        }
    }
    return 0;
}
