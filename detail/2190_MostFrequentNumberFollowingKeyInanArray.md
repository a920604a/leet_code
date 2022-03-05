---
title: 2190. Most Frequent Number Following Key In an Array
tags:
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/)


## solution
```c++
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int  n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;++i){
            if( nums[i] == key){
                mp[nums[i+1]]++;
            }
        }
        int target = 0, freq = 0;
        for(auto m:mp){
            if(m.second >freq){
                freq = m.second;
                target = m.first;
            }
        }
        
        return target;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`