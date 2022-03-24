---
title: 342. Power of Four

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/power-of-four/)

## solution
#### option 1
```c++
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        while(n%4==0) n>>=2;
        return n==1;
    }
};
```
#### option 2
```c++
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        if((n&(n-1))!=0) return false;
        return (n&0x55555555) ==n;
    }
};
```
#### option 3 - 換底公式
```c++
class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n>0 && int(log10(n)/log10(4))-log10(n)/log10(4)==0 );
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`

