// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    // option 1 
    // int n = A.size();
    // int total = (n+2)*(n+1)/2;
    // for(int a:A) total -= a;
    // return total;

    // option 2
    int n = A.size();
    int ret = n;
    for(int i=0;i<n;++i){
        ret ^= i^(A[i]-1);
    }
    return ret+1;


}