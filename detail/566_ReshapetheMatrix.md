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
- easy understand
```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n*m != r*c) return mat;
        vector<vector<int>> ret(r, vector<int>(c,0));
        int k =0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                ret[i][j] = mat[k/m][k%m];
                k++;
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`