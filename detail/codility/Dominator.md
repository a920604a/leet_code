---
title: Dominator
categories: 
    - codility
    - Leader
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/8-leader/dominator/)

## solution

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty()) return -1;
    int n = A.size();
    int cand = A[0], count = 1;
    for(int i=1;i<n;++i){
        if(cand == A[i]) count++;
        else{
            count--;
            if(count ==0){
                cand = A[i];
                count = 1;
            }
        }
    }
    /// check more than half 
    count = 0;
    for(int a:A) count+=(a==cand?1:0);
    if(count<=n/2) return -1;
    // find the index of dominator
    for(int i=0;i<n;++i){
        if(A[i] == cand) return i;
    }
    return -1;
}
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`


