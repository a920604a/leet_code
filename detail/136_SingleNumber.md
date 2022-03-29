---
title: 136. Single Number

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/single-number/)

- 給定一維整數陣列，找出那個single number，假設其他數字皆會出現兩次

## solution
#### option 1 - hash table
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int n:nums) m[n]++;
        for(int n:nums){
            if(m[n]==1) return n;
        }
        return -1;
    }
};
```
> set/map find operation better than count operation, find 找到就return ，count則會繼續拜訪。
#### option 2 - Bit Manipulation
- 善用 `x^x=0`特性 以及 XOR交換率

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int n:nums) ret^=n;
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
