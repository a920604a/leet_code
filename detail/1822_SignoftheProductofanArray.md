---
title: 1822. Sign of the Product of an Array
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sign-of-the-product-of-an-array/)


## solution
```c++
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ret = 1;
        for(int n:nums){
            // avoid overflow
            if(n<0) ret*=(-1);
            else if(n==0) return 0;
        }
        return ret<0?-1:1;
    }
};
```