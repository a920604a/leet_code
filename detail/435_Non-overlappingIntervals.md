---
title: 435. Non-overlapping Intervals
tags:  
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/non-overlapping-intervals/)

## solution

```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int count = 1, n = intervals.size();
        int end = intervals[0][1];
        for(int i=1;i<n;++i){
            vector<int> & cur = intervals[i];
            // 不重疊，注意這裡等於算不同區間
            if(end<=cur[0]){
                end = cur[1];
                count++;
            }
        }
        return n - count;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- speed complexity `O(1)`
