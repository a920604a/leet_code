---
title: 2295. Replace Elements in an Array
tags:
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/replace-elements-in-an-array/)

## solution
```c++
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;++i) mp[nums[i]] = i;
        for( auto op : operations){
            nums[mp[op[0]]] = op[1];
            mp[op[1]] = mp[op[0]];
            mp.erase(op[0]); // option
        }
        return nums;
    }
};
```

## analysis
- time complexity `O(logn)` 
- space complexity `O(n)`  can reduce `O(1)`