---
title: 991. Broken Calculator
tags:
    - greedy 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/broken-calculator/)

## solution 
- iterative
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

- recursive
```c++
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue==target ) return 0;
        if(startValue > target) return startValue-target;
        if( target%2==1) return 1+brokenCalc(startValue, target+1);
        else return 1+brokenCalc(startValue, target/2);
        
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
