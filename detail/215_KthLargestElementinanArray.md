---
title: 215. Kth Largest Element in an Array
tags:  
    - heap
categories: leetcode
comments: false
---

## [problem](https://)

## solution
- version 1
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;    
        for(int n:nums) pq.push(n);
        int ret ;
        while(k--){
            ret = pq.top();
            pq.pop();
        }
        return ret;
    }
};
```
- version 2
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n:nums){
            pq.push(n);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`
