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
        auto cmp = [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp);
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        for( auto m:mp) pq.push({m.first, m.second});
        while(k--){
            ret.push_back(pq.top()[0]);
            pq.pop();
        }
        
        return ret;
        
    }
};
```
#### option 2 - bucket sorting
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int a:nums) mp[a]++;
        vector<vector<int>> bucket(nums.size());
        int f = 0;
        for(auto m:mp){
            bucket[m.second-1].push_back(m.first);
            f = max(f, m.second-1);
        }
        bucket.resize(f+1);
        vector<int> ret;
        for(int i = f;i>-1 ; i--){
            int cur = bucket[i].size()-1;
            while(k > 0 && cur > -1 ){
                ret.push_back(bucket[i][cur--]);
                k--;
            }
        }
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogK)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`
    