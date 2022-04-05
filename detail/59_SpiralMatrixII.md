---
title: 59. Spiral Matrix II
tags: 
    - Matrix
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/spiral-matrix-ii/)

## solution 
維護一組陣列，控制下一步要走的方向

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n,0));
        vector<bool> visited(n*n,false);
        int a[4] = {0,1,0,-1};
        int i = 0, j=-1, t =1, k=0;
        while(t<=n*n){
            
            int x = i+a[k%4] ,  y = j+a[(k+1)%4];
            while(x<0 || y<0 || x>n-1 || y>n-1 || visited[x*n+y]){
                k++;
                x = i+a[k%4] ,  y = j+a[(k+1)%4];
            }
            visited[x*n+y] = true;
            ret[x][y] = t++;
            i = x, j = y;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`