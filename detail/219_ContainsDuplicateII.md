---
title: 219. Contains Duplicate II
tags: 
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/contains-duplicate-ii/)

## solution
```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;++i){
            if(mp.count(nums[i])){
                if(( i - mp[nums[i]])<=k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
        
        
    }
};
```

## analysis
- time complexity `O(nlogn)`
- speed complexity `O(n)`