---
title: 2208. Minimum Operations to Halve Array Sum
tags:
    - heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/)

## solution

#### option 1 - heap
```c++
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total = 0;
        for(int n:nums){
            pq.push(n);
            total+=n;
        }
        int step = 0;
        double cur = total;
        while(cur > total/2.0){
            double p = pq.top(); pq.pop();
            p /= 2.0;
            cur -= p;
            pq.push(p);
            step++;
        }
        return step;   
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `(n)`