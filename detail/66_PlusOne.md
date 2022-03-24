---
title: 66. Plus One
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/plus-one/)

## solution
```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n= digits.size()-1;
        while(n>-1){
            if(digits[n] == 9){
                digits[n]= 0;
                n--;
            }
            else{
                digits[n]++;
                break;
            }
        }
        if(digits[0] == 0) digits.insert(digits.begin() ,1);
        
        return digits;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`