---
title: 268. Missing Number

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/missing-number/)

給定一維陣列，那一個數字遺失

## solution

#### math
三角形公式

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;
        for(int n:nums) total-=n;
        return total;
        
    }
};
```
- total變數，可能會有overflow 問題

#### Bit
- 善用 `x^x=0` 以及 XOR交換率
- 因題目限制，陣列元素只會是正整數，利用陣列索引與元素做XOR

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ret = n;
        for(int i=0;i<n; ++i) ret^= (i^nums[i]);
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
