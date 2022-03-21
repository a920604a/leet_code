---
title: 172. Factorial Trailing Zeroes
tags:  
    - dp
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/factorial-trailing-zeroes/)

給定一數字n，返回n!有多少個0結尾

## solution 


#### option 1 - recursive
```c++
class Solution {
public:
    int trailingZeroes(int n) {
        // 給定一數字n，返回n!有多少個0結尾
        //  0   1   2   3   4   5   6   7       8       9       10  11  12  13  14  15  16  17  ... 25
        //  1   1   2   6   24  120 720 5040    40320   362880  3628800     
        //  0   0   0   0   0   1   1   1       1       1       2   2   2   2   2   3   3   3       6
        // 找出陣列[0-n] 中數字除以5的總和
        if(n<5) return 0;
        return n/5 + trailingZeroes(n/5);
    }
};

```


#### option 2 - iterative
```c++
class Solution {
public:
    int trailingZeroes(int n) {
        // 給定一數字n，返回n!有多少個0結尾
        //  0   1   2   3   4   5   6   7       8       9       10  11  12  13  14  15  16  17  ... 25
        //  1   1   2   6   24  120 720 5040    40320   362880  3628800     
        //  0   0   0   0   0   1   1   1       1       1       2   2   2   2   2   3   3   3       6
        // 找出陣列[0-n] 中數字除以5的總和
        int ret = 0;
        for(int d = n;d>4 ; d/=5){
            ret+= d/5;
        }
        return ret;
        
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`