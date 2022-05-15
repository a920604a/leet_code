---
title: 2270. Number of Ways to Split Array
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-ways-to-split-array/)

## solution
```c++
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0, n=nums.size();
        long long cur = 0, total = 0;
        for(int n:nums) total+=n;
        for(int i=0;i<n-1;++i){
            cur+=nums[i];
            total-=nums[i];
            if(cur>=total) count++;
        }
        return count;
    }
};
```

## ananlysis
- time complexity `O(n)`
- space complexity `O(1)`