---
title: 57. Insert Interval
tags:  
    - Interval
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/insert-interval/)

## solution

類似`56. Merge Intervals`，先將`newInterval` 加進 `intervals`

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0] ) return a[1]>b[1];
            return a[0]<b[0];
        });
        int n = intervals.size();
        int start = intervals[0][0], end = intervals[0][1];
        ret.push_back({start, end});
        for(int i=1;i<n;++i){
            vector<int>& cur = intervals[i];
            // overlap
            if(end >= cur[0]){
                end = max(end, cur[1]);
                ret.back()[1] = end;
            }
            else{
                ret.push_back(cur);
                start = cur[0];
                end = cur[1];
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`