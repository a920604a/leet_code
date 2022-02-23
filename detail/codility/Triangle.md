---
title: Triangle
categories: 
    - codility
    - sorting
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/6-sorting/triangle/)

## solution
注意避免 overflow
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i=1;i<n-1;++i){
        if(
            A[i-1] > A[i+1] - A[i]
            // A[i+1] + A[i-1] > A[i] && \
            // A[i] + A[i+1] > A[i-1] && \

        ) return true;
    }
    return false;
}
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`
