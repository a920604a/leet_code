---
title: MaxDoubleSliceSum
categories: 
    - codility
    - Mamimum Slice problem
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/)

## solution
Bi-direct Kadane’s Algorithm

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<vector>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    //      3   2   6   -1  4   5   -1  2
    //l     0   2   8   7   11  16  15  0
    //r     0   15  14  8   9   5   0   0
    //          14  10  17  12  11  16  

    // 14 => (X,Y,Z) = (0,1,6)
    // 10 => (X,Y,Z) = (0,2,6)
    // 17 => (X,Y,Z) = (0,3,6)
    // 12 => (X,Y,Z) = (0,4,6)
    // 11 => (X,Y,Z) = (0,5,6)
    // 16 => (X,Y,Z) = (0,6,7)
    
    // Bi-direct
    vector<int> left(n,0), right(n,0);
    for(int i=1;i<n-1;++i) left[i] = max(left[i-1] + A[i], 0);
    for(int i=n-2;i>0 ;--i) right[i] = max(right[i+1]+A[i], 0);
    int ret = 0;
    for(int i=1;i<n-1;++i) ret= max(ret, left[i-1] + right[i+1]);
    return ret;
}
```



## analysis
- time complexity `O(n)`
- space complexity `O(1)`


