---
title: 452. Minimum Number of Arrows to Burst Balloons
tags:  
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

## solution
```c++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
           return a[1]<b[1];
        });
        int n = points.size(), count = 1, end = points[0][1];
        for(int i=1;i<n;++i){
            vector<int>& cur = points[i];
            // 區間邊界觸碰也算重疊
            
            // 不重疊狀況
            if(end < cur[0]){
                count++;
                end = cur[1];
            }
        }
        return count;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- speed complexity `O(1)`
