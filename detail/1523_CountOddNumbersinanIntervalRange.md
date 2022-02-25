---
title: 1523. Count Odd Numbers in an Interval Range
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)


## solution
```c++
class Solution {
public:
    int countOdds(int low, int high) {
        int l=low, r = high;
        int count = 0;
        while(l<r && l%2==0) l++;
        while(l<r && r%2==0) r--;
        if(l==r) return l%2==1?1:0;
        return (r-l)/2+1;
        
    }
};
```