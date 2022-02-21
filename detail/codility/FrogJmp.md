---
title: FrogJmp
categories: 
    - codility
    - Time Complexity
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    Y -=X;
    if(Y%D!=0) return Y/D+1;
    else return Y/D;
}

```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`


