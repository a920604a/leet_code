---
title: 292. Nim Game
tags:
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/nim-game/)
## solution
```c++
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`
