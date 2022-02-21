---
title: 56. Merge Intervals
tags:  
    - Interval
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/merge-intervals/)

## solution

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 先排序，再觀察規律
        // 按區間的start 升序排序 
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){
            return a[0]<b[0];
        });
        vector<vector<int>> ret;
        int n = intervals.size(), start =intervals[0][0], end= intervals[0][1];
        ret.push_back({start, end});
        for(int i=1;i<n;++i){
            vector<int>&  cur = intervals[i];
            // 找到有區間有重疊，並更新最大的end
            if(ret.back()[1] >= cur[0]){
                ret.back()[1] =max( cur[1], ret.back()[1]);
            }
            // 處理下一個區間
            else{
                ret.push_back(cur);
            }
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`