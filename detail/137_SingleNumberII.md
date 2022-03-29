---
title: 137. Single Number II

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/single-number-ii/)

從一維陣列找出那個不重複的數字，假設其他數字皆會出現三次
## solution

- 利用2進位表示法，逐一去將第i位元相加，並除以3

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=31;i>-1;--i){
            int sum = 0;
            for(int n:nums){
                sum+= (n>>i)&1;
            }
            sum%=3;
            ret+= sum<<i;
        }
        return ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
