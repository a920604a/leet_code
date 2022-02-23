---
title: MinPerimeterRectangle
categories: 
    - codility
    - Prime and composite numbers
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/)

## solution
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int perimeter = (N+1);
    for(int i=1;i*i<=N ; ++i){
        if(N%i ==0){
            perimeter = min(perimeter, i+N/i);
        }
    }
    return 2*perimeter;
}
```
## analysis
- time complexity `O(sqrt(n))`
- space complexity `O(1)`