---
title: 258. Add Digits
tags:
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/add-digits/)
## solution
```c++
class Solution {
public:
    int addDigits(int num) {
        int n = num ;
        while(n>=10){
            int sum = 0;
            while(n){
                sum+=(n%10);
                n/=10;
            }
            n = sum;
        }
        return n;
        
    }
};
```