---
title: 347. Top K Frequent Elements

tags:  
    - Heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/top-k-frequent-elements/)



## solution

#### option 1 - heap
- 先用一個hash table 紀錄每個數字與其出次數
- 用一個heap，並自定義比較的函數，將`{數字,出現次數 }` push into heap
- heap pop


```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        auto cmp  = [](vector<int> & a, vector<int>& b){
            return a[1]<b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(auto m:mp){
            vector<int> temp(2,0);
            temp[0] = m.first;
            temp[1] = m.second;
            pq.push(temp);
        }
        while(!pq.empty() && k-->0){
            vector<int> temp = pq.top();
            pq.pop();
            ret.push_back(temp[0]);
            
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O()`