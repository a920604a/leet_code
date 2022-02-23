---
title: Distinct
categories: 
    - codility
    - sorting
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/6-sorting/distinct/)

## solution


#### option 1 - set
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> s;
    for(int a:A) s.insert(a);
    return s.size();
}
```

#### option 2 -

```c++

```
## analysis
- optino 1 
    - time complexity `O(n)`
    - space complexity `O(n)`