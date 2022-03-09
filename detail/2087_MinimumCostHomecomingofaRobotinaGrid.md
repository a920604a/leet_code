---
title: 2087. Minimum Cost Homecoming of a Robot in a Grid
tags:  
    - Greedy
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)


## solution

```c++
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ret = 0;
        int i = startPos[0], j = startPos[1], x = homePos[0], y = homePos[1];
        
        if(i<x){
            for(int c = i+1 ; c<=x;++c) ret+=rowCosts[c];
        }
        else if(i>x){
            for(int c = i-1;c>=x;--c) ret+=rowCosts[c];
        }
        if(j<y){
            for(int c = j+1;c<=y;++c) ret+=colCosts[c];
        }
        else if(j>y){
            for(int c = j-1;c>=y;--c) ret+=colCosts[c];
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(1)`