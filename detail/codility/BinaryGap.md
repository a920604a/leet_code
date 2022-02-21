---
title: BinaryGap
categories: 
    - codility
    - iteration
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/1-iterations/binary_gap/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int i= 0, j=0, ret = 0;
    while(N>0 && (N&1)==0) {
        i++;
        N>>=1;
    }
    j=i;
    while(N){
        if(N&1){
            ret = max(ret, i-j);
            i=j ;
        }
        else i++;
        N>>=1;
    }
    return ret;
}

```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`


