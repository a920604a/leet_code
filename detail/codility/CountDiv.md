---
title: CountDiv
categories: 
    - codility
    - Prefix Sum
comments: false
---
## [problem](https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    // if(K==1) return B-A+1;
    while(A<B && A%K!=0) A++;
    while(A<B && B%K!=0) B--;
    if(A%K!=0) return 0;
    return (B-A)/K+1; 
}
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`