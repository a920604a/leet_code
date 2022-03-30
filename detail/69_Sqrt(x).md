---
title: 69. Sqrt(x)
tags:
    - math
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sqrtx/)

## solution
#### option 1
```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x< 2) return x;
        
        int ret = 0, i ;
        for(i=1;i*i<=x;++i){
            if(i+1> INT_MAX/(i+1)) return i;
        }
        return i-1;
    }
};
```
#### option 2 - Binary Search
```c++
```

## analysis
- time complexity `O(sqrt(n))` `O(logn)`
- space complexity `O(1)`