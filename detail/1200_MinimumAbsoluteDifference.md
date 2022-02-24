---
title: 1200. Minimum Absolute Difference
tags:  
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-absolute-difference/)


## solution
```c++
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ret;
        sort(arr.begin(),arr.end());
        int mn_abs = arr[1] - arr[0], n = arr.size();
        for(int i=1;i<n ; ++i) mn_abs = min(mn_abs, arr[i] - arr[i-1]);
        for(int i=1;i<n;++i){
            if(arr[i] - arr[i-1] == mn_abs) ret.push_back({arr[i-1], arr[i]});
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`
