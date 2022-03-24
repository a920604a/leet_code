---
title: 168. Excel Sheet Column Title
tags: 
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/excel-sheet-column-title/)

## solution

```c++
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while(columnNumber){
            int mod = (--columnNumber)%26;
            char c = mod+'A';
            ret = c+ret;
            columnNumber/=26;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`