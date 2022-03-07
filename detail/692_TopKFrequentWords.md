---
title: 692. Top K Frequent Words
tags:  
    - Heap
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/top-k-frequent-elements/)

## solution
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int,int> freq;
        for(int n:nums) freq[n]++;
        auto cmp = [](vector<int>& a, vector<int>&b){
            return a[1]<b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(auto m:freq) pq.push({m.first, m.second});
        while(k--){
            vector<int> p = pq.top();
            pq.pop();
            ret.push_back(p[0]);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`