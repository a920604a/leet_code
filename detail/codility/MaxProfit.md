---
title: MaxProfit
categories: 
    - codility
    - Mamimum Slice problem
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/)

一次的股票交易最大可以獲得多少獲益

## solution

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return 0;
    int mn = A[0], profit = 0;
    for(int a:A){
        mn = min(mn, a);
        profit = max(profit, a-mn);
    }
    return profit;
}


```



## analysis
- time complexity `O(n)`
- space complexity `O(1)`


