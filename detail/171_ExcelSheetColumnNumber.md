---
title: 171. Excel Sheet Column Number
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/excel-sheet-column-number/)

## solution

```c++
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0, n = columnTitle.size();
        for(int i=0;i<n;i++){
            ret = 26*ret ;
            ret+=columnTitle[i]-'A'+1;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`