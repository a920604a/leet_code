---
title: 7. Reverse Integer

tags:  
    - Bit Manipulation
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-integer/)
Given a 32-bit signed integer, reverse digits of an integer.


## solution
- 要注意是否會overflow，在每次將結果加到ret變數時都必須檢查是否overflow
#### option 1
```c++
class Solution {
public:
    int reverse(int x) {
        
        int ret = 0;
        while(x){
            if(abs(ret) > INT_MAX/10) return 0;
            ret = 10*ret + (x%10);
            x/=10;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`


