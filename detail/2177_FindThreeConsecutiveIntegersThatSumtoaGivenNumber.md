---
title: 2177. Find Three Consecutive Integers That Sum to a Given Number
tags:  
    - math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution

```c++
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // 1 2 3 -> 6
        // 2 3 4 -> 9
        // 3 4 5 -> 12
        // 4 5 6 -> 15
        vector<long long>  ret;
        if(num%3!=0) return ret;
        long long mid = num/3;
        return {mid-1, mid, mid+1};
        
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`