---
title: 1779. Find Nearest Point That Has the Same X or Y Coordinate
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)


## solution
```c++
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size(), mn = INT_MAX, ans = -1, manhattan;
        for(int i = 0; i < n; i++)
            if(points[i][0] == x || points[i][1] == y){
                manhattan = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(manhattan < mn)
                    mn = manhattan, ans = i;            
            }
            return ans;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`