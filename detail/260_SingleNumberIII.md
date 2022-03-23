---
title: 260. Single Number III
tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/single-number-iii/)
## solution
```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = 0;
        for(int n:nums) diff^=n;
        diff &= (-diff);
        int a=0, b=0;
        for(int n:nums){
            if(n&diff) a^= n;
            else b^=n;
        }
        return {a,b};
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`