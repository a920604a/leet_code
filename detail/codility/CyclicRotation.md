---
title: CyclicRotation
categories: 
    - codility
    - Array
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/)


## solution 

#### option 1 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return A;
    int n = A.size();
    K %=n;
    vector<int> ret(n,0);
    for(int i=0;i<n;++i) ret[i] = A[(n-K+i)%n];
    return ret;
}

```

#### option 2 - reverse
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)

    if(A.empty()) return A;
    int n = A.size();
    K %=n;
    reverse(A.begin(), A.begin()+n-K);
    reverse(A.begin()+n-K, A.end());
    reverse(A.begin(), A.end());
    return A;
}
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`


