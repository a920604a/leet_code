---
title: 2235. Add Two Integers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/add-two-integers/)

## solution
#### option 1 - native
```c++
class Solution {
public:
    int sum(int num1, int num2) {
        return num1+num2;
    }
};
```
#### option 2 - without `+`
```c++
class Solution {
public:
    int sum(int num1, int num2) {
        while(num2!=0){
            unsigned int total = num1^num2;
            unsigned int carry = num1&num2;
            
            num1 = total;
            num2 = carry<<1;
        }
        return num1;
    }
};
```
```c++
class Solution {
public:
    int sum(int num1, int num2) {
        while(num2){
            int carry = (num1&num2&0x7fffffff)<<1, total = num1^num2;
            num2 = carry, num1 = total;
        }
        return num1;
    }
};
```
