---
title: 463. Island Perimeter
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/island-perimeter/)


## solution
```c++
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 0) continue;
                // 假設每個方塊周長為4，如果相鄰有其他方塊則減一
                int count =4;
                if(i>0 && grid[i-1][j] ==1 ) count--;
                if(j>0 && grid[i][j-1] ==1 ) count--;
                if(i+1<n && grid[i+1][j] ==1 ) count--;
                if(j+1<m && grid[i][j+1] ==1 ) count--;
                perimeter+=count;
            }
        }
        return perimeter;
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(1)`
