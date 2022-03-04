---
title: 1572. Matrix Diagonal Sum
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/matrix-diagonal-sum/)


## solution
one pass
```c++
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), idx = 0, ret = 0;
        for(int i=0;i<n;++i){
            ret+=mat[i][idx];
            if(idx != n-1-idx) ret+=mat[i][n-1-idx];
            idx++;
        }
        return ret;
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(1)`