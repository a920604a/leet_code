---
title: 9. Palindrome Number
tags:  
    - Bit Manipulation
    - Math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/palindrome-number/)
## solution

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        // 0, 1,2,3,4,5,6,7,8,9 => true
        // 10 , 100, x0, x00 => false
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int ret = 0;
        while(ret < x){
            ret = 10*ret + (x%10);
            x/=10;
        }
        return ( ret==x || ret/10 == x);
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`