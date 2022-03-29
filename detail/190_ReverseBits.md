---
title: 190. Reverse Bits

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-bits/)

## solution
利用 `>>i` 取得第i位元

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i=0;i<32;++i){
            ret<<=1;
            ret += (n>>i)&1;
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`

