---
title: 201. Bitwise AND of Numbers Range
tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/bitwise-and-of-numbers-range/)
## solution

#### option 1 
不斷向右shift ，直到兩數字相等
```c++
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 5 = 0101
        // 7 = 0111
        int i=0;
        while(left != right){
            left>>=1;
            right>>=1;
            i++;
        }
        return right<<i;
    }
};
```

#### option 2 
概念與option 1一樣，答案必定為2的指數
```c++
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //      8   4   2   1
        //5     0   1   0   1
        //6     0   1   1   0
        //7     0   1   1   1
        
        while (right > left) {
              right&= (right-1);
         }
         return right;
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
