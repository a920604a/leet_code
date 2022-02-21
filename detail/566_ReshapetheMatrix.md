---
title: 566. Reshape the Matrix
tags:  
    - Matrix
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/reshape-the-matrix/)

## solution
```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ret(r, vector<int>(c,0));
        if(r*c!=mat.size()*mat[0].size()) return mat;
        int k =0, n = mat[0].size();
        for(int i=0;i<r;i++){
            for(int j = 0;j<c;++j){
                k = i*c+j;
                ret[i][j] = mat[k/n][k%n];
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`