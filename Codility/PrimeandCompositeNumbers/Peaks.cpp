// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    

    // option 1 time out
    // vector<bool> factor(N, false);
    // //  1   2   3   4   5   6   7   8
    // //  t   t   f   t   f   f   f   t

    // for(int i=1;i<=N/2;++i){
    //     if( N%i==0){
    //         factor[i-1] = true;
    //         factor[ N/i -1] = true;
    //     }
    // }
    // int count = 0;
    // for(bool f:factor) count+=f;
    // return count;

    // option 2 
    if(N==1) return 1;
    int ret = 0;
    int i;
    for(i=1 ; i<N/i;++i){
        if(N%i==0) ret +=2;

    }
    if(i*i==N) ret++;
    return ret;
}
