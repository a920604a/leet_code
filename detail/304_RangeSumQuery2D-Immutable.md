---
title: 304. Range Sum Query 2D - Immutable
tags:  
    - Prefix Sum
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/range-sum-query-2d-immutable/)

## solution

```c++
class NumMatrix {
private:
    vector<vector<int>>prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefixSum = vector<vector<int>>(n+1, vector<int>(m+1,0));
        //  3   0   1   4   2   
        //  5   6   3   2   1
        //  1   2   0   1   5
        //  4   1   0   1   7
        //  1   0   3   0   5
        
        //  0   0   0   0   0   0
        //  0   3   3   4   8   10
        //  0   8   14  18  24  27
        //  0   9   17  21  28  36
        //  0   13  22  26  34  49
        //  0   14  23  30  38  58
        
        for(int i =1;i<n+1; ++i){
            for(int j =1;j<m+1;++j) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row1][col1] + prefixSum[row2+1][col2+1] - prefixSum[row1][col2+1] - prefixSum[row2+1][col1];
        
    }
};

```
## analysis
- `sumRegion` 函數 time complexity `O(1)`