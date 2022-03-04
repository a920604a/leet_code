---
title: 263. Ugly Number
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/ugly-number/)


## solution
```c++
class Solution {
public:
    bool isUgly(int n) {
        if(n<1)  return false;
        while(n%2==0) n>>=1;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1;   
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`