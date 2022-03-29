---
title: 73. Set Matrix Zeroes

categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/set-matrix-zeroes/)

## solution 

1. 將第一列與第一行是否有出現零，設置`flag = true;`
2. 除了第一列第一行的其餘陣列，如果有0出現，則將對應的第一行或第一列設為0
3. 遍歷除了第一列第一行得其餘數陣列，如果當前第一行第一列為0，則該位置設置為0
4. 根據`flag` 更新第一行第一列為0


```c++
class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool isFirstCol = false, isFirstRow = false;
        for(int i=0;i<n;++i){
            if(matrix[i][0] == 0) isFirstCol = true;
        }
        for(int j=0;j<m;++j){
            if(matrix[0][j] ==0 ) isFirstRow = true;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(matrix[i][0] ==0 || matrix[0][j] ==0) matrix[i][j] = 0;
            }
        }
        
        if(isFirstRow){
            for(int j=0;j<m;++j) matrix[0][j] = 0;
        }
        if(isFirstCol){
            for(int i=0;i<n;++i) matrix[i][0] = 0;
        }
        
    }
};
```
## analysis

