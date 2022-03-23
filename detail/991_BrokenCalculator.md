---
title: 991. Broken Calculator
tags:
    - greedy 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/broken-calculator/)

## solution 
```c++
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret= 0;
        while(target > startValue){
            target = (target%2==0)?target/2:target+1;
            ret++;
        }
        return ret+startValue-target;
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
