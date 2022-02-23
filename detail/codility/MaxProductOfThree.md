---
title: MaxProductOfThree
categories: 
    - codility
    - sorting
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/)

## solution

三值相乘最大值，只會發生在最小兩個（負數）乘以最大，或是前三大（正數)相乘

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
    return max(A[0]*A[1]*A[n-1],A[n-3]*A[n-2]*A[n-1] );
}

```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`