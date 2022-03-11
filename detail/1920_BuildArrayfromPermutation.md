---
title: 1920. Build Array from Permutation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/build-array-from-permutation/)


## solution


#### option 1 
```c++
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> ret;
        for(int i=0;i<n;++i){
            ret.push_back(nums[nums[i]]);
        }
        return ret;
    }
};
```
#### option 2 - follow up `O(1)` space

## analysis
- time complexity `O(n)`
- space complexity `O(n)`