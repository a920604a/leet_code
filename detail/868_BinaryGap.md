---
title: 868. Binary Gap
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/binary-gap/)


## solution
```c++
class Solution {
public:
    int binaryGap(int n) {
        // if n is 2-power return false;
        if( (n&(n-1))==0) return false;
        int gap = 0;
        int i = 0, j=0;
        bool flag = false;
        while(n){
            if(n&1){
                if(flag==false){
                    // 第一次
                    flag = true;
                }
                else{
                    gap = max(gap , i-j);
                }
                j =i ;
            }
            i++;
            n>>=1;
        }
        return gap;
    }
};
```


## analysis
- time complexity `O(logn)`
- space complexity `O(1)`