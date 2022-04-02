---
title: 2222. Number of Ways to Select Buildings
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-ways-to-select-buildings/)

## solution
need four variable , reprsentation 
- the number of visited zero
- the number of unvisited zero
- the number of visited one
- the number of unvisited one

```c++
class Solution {
public:
    long long numberOfWays(string s) {
        int unused_zeros = 0, unused_ones  = 0, n = s.size();
        for(char c:s) unused_ones+=(c=='1');
        unused_zeros = n - unused_ones;
        long long ret = 0;
        int used_zeros =0, used_ones = 0;
        for(char c:s){
            if(c == '1'){
                // 010
                ret+=unused_zeros*used_zeros;
                used_ones++;
                unused_ones--;  
            }
            else{
                //101
                ret+=unused_ones*used_ones;
                used_zeros++;
                unused_zeros--;                   
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`