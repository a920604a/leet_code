---
title: MaxSliceSum
categories: 
    - codility
    - Mamimum Slice problem
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/)

## solution

Kadane’s Algorithm

```c++

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int local = 0, global = -1000000;
    for(int a:A){
        local = max(a, a+local);
        global = max(global, local);
    }
    return global;
}
```


## analysis
- time complexity `O(n)`
- space complexity `O(1)`


