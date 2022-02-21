---
title: PermMissingElem
categories: 
    - codility
    - Time Complexity
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/)


## solution 


#### option 1 - XOR
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size(), ret = n+1;
    for(int i=0;i<n;++i) ret^= ((i+1)^A[i]);
    return ret;
}
```

#### option 2 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size(), total = n+1;
    for(int i=0;i<n;++i) total+=(i+1-A[i]);
    return total;
}

```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`


