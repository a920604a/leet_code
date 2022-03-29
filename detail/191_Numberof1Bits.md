---
title: 191. Number of 1 Bits

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/number-of-1-bits/)

## solution
利用 `n&(n-1)` 找 n 在二進位表示中有多少個1

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            ret++;
            n &=(n-1);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`

