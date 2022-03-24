---
title: 326. Power of Three

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/power-of-three/)

## solution
#### option 1 iterative and recursive

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        while(n%3==0) n/=3;
        return n==1;
    }
};
```
```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        if(n%3==0) return isPowerOfThree(n/3);
        return n==1;
        
    }
};
```
因為在`[0,2^31-1]` 之間最大的三次方數為`3^19 = 1162261467`

```c++
return (n > 0 && 1162261467 % n == 0);
```
#### option 2 - 換底公式
```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n>0 && int(log10(n)/log10(3))-log10(n)/log10(3)==0 );
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`

