---
title: OddOccurrencesInArray
categories: 
    - codility
    - Array
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ret = 0;
    for(int a:A) ret^=a;
    return ret;
}
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`

