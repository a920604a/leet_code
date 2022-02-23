---
title: CountFactors
categories: 
    - codility
    - Prime and composite numbers
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/)

## solution
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<math.h>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int factors = 0;
    // i*i<= N , will cause overflow
    for(int i=1;i<=sqrt(N); ++i){
        if(i*i==N) factors++;
        else if(N%i==0) factors+=2;
    }
    
    return factors;
}

```
## analysis
- time complexity `O(sqrt(n))`
- space complexity `O(1)`