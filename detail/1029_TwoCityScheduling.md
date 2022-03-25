---
title: 1029. Two City Scheduling
tags:  
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/two-city-scheduling/)

## solution
```c++
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0, n = costs.size()/2;
        vector<int> refund;
        for(auto & cost:costs){
            ret+=cost[0];
            refund.push_back(cost[1] - cost[0]);
        }
        sort(refund.begin(), refund.end());
        for(int i=0;i<n;++i) ret+=refund[i];
        return ret;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`