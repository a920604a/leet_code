---
title: 1260. Shift 2D Grid
tags:
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/shift-2d-grid/)
## solution
### option 1
```c++
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> vec;
        int n =grid.size(), m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                vec.push_back(grid[i][j]);
            }
        }
        k%= m*n;
        k = m*n-k;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                grid[i][j] = vec[k%(m*n)];
                k++;
            }
        }
        return grid;
    }
};
```
#### option 2 - `O(1)`
## analysis
- time complexity `O(mn)`
- space complexity `O(nm)` `O(1)`