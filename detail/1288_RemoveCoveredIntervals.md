---
title: 1288. Remove Covered Intervals
tags:  
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-covered-intervals/)

## solution

```c++
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        // 不斷擴張領土[start, end]
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int start = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();
        for(int i=1;i<n;++i){
            vector<int>& cur = intervals[i];
            // 完全覆蓋，
            if(end>=cur[1]){
                count++;
            }
            // 區間重疊，擴張領土
            else if(end>= cur[0] && end<cur[1]){
                end = cur[1];
                
            }
            // non-overlap
            else{
                start = cur[0];
                end = cur[1];
            }
        }
        return n-count;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`