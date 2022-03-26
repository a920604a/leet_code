---
title: 118. Pascal's Triangle
tags:  
    - dp
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/pascals-triangle/)

## solution
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret = {{1}};
        if(numRows==1) return ret;
        vector<int> row = {1};
        for(int i=2;i<=numRows;++i){
            
            int pre = row[0];
            for(int j = 1;j<i-1 ; ++j){
                int cur = row[j];
                row[j] +=pre;
                pre = cur;
            }
            row.push_back(1);
            ret.push_back(row);
        }
        return ret;      
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(nm)`