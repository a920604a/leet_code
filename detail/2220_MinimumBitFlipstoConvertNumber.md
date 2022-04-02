---
title: 2220. Minimum Bit Flips to Convert Number
tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)
## solution
```c++
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start^goal, count = 0;
        // count one
        while(n){
            n &=(n-1);
            count++;
        }
        return count;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
