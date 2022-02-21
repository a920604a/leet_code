---
title: FrogRiverOne
categories: 
    - codility
    - Counting Elements
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/)


## solution 

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<unordered_set>
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // 第幾秒落葉會不滿整個[1..X]地方
    unordered_set<int> s;
    int n = A.size();
    for(int i=0;i<n;++i){
        s.insert(A[i]);
        if(s.size()==X) return i;
    }
    return -1;
}

```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`


