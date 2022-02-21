---
title: TapeEquilibrium
categories: 
    - codility
    - Time Complexity
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int total = 0, ret = 100000, n = A.size(), sum = 0;
    for(int a:A) total +=a;
    for(int i=0;i<n-1;++i) {
        sum+=A[i];
        ret = min(ret, abs(total-2*sum) );
    }
    return ret;
}

```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`


