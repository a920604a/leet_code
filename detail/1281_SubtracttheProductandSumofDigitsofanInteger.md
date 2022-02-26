---
title: 1281. Subtract the Product and Sum of Digits of an Integer
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

## solution
```c++
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        while(n){
            prod *= (n%10);
            sum+=(n%10);
            n/=10;
        }
        return prod - sum;
    }
};
```

## analysis
- time complexity `O(logn)`
- sparse complexity `O(1)`