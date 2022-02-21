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
        // 排序，按起點升序，起點相同案終點降序
        
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>&b){
            if(a[0] == b[0] ) return a[1]>b[1];
            return a[0]<b[0];
        });
        int n = intervals.size(), start = intervals[0][0], end = intervals[0][1];
        int remove = 0;
        for(int i=1;i<n;++i){
            vector<int> & cur = intervals[i];
            // [1,4] [3,5] 區間重疊 => 將end 向右擴張
            if( end >= cur[0] && end<cur[1]){
                end = cur[1];
            }
            // [1,4] [2,3] 完全覆蓋 => 可以覆蓋一個區間。
            else if(end>= cur[0] && end>=cur[1]){
                remove++;
            }
            // [1,2] [4,6] 不重疊
            else{
                start = cur[0];
                end = cur[1];
            }
        }
        return n - remove;
        
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`