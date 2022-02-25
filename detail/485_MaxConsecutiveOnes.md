---
title: 485. Max Consecutive Ones
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/max-consecutive-ones/)

## solution
```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, ret = 0;
        for(int n:nums){
            if(n==1) count++;
            else {ret=  max(ret, count); count= 0;}
        }
        return max(ret, count);
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
