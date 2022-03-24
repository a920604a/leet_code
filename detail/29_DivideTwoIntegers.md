---
title: 29. Divide Two Integers
tags:  
    - Math
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/divide-two-integers/)
## solution
```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend), n = labs(divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};
```

## analysis
- time complexity `O(logn)`
- space compleity `O(1)`