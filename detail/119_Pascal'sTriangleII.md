---
title: 119. Pascal's Triangle II
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/pascals-triangle-ii/)

## solution
```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        for(int i=1;i<=rowIndex ; ++i){
            int pre = ret[0];
            for(int j=1;j<i ; ++j){
                int cur = ret[j];
                ret[j] += pre;
                pre = cur;
            }
            ret.push_back(1);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`