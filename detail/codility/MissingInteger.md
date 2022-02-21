---
title: MissingInteger
categories: 
    - codility
    - Counting Elements
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/)


## solution 

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int n = A.size(), c =1;
    for(int i=0;i<n;++i){
        if(A[i] == c) c++;
        while(i<n-1 && A[i] == A[i+1] ) i++;
    }
    return c;
}

```


## analysis
    - time complexity `O(nlogn)`
    - space complexity `O(1)`


