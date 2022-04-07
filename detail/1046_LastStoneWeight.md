---
title: 1046. Last Stone Weight
tags:  
    - Heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/last-stone-weight/)
## solution
#### option 1 - heap
```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()!=1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(a-b);
        }
        return pq.top();
        
    }
};
```
#### option 2 - counting sort
```c++
```
## analysis
- option 1 - heap
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 2 - sort
    - time complexity `O(n)`
    - space complexity `O(1)`