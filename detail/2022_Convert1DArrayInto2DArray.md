---
title: 2022. Convert 1D Array Into 2D Array
tags:  
    - Matrix
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/convert-1d-array-into-2d-array/)

## solution
```c++
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret;
        if(original.size()  != m*n) return ret;
        ret = vector<vector<int>>(m,vector<int>(n,0));
        int k =0 , c = original.size();
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;++j){
                ret[i][j] = original[k++];
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
