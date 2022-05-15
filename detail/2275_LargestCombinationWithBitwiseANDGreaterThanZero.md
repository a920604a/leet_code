---
title: 2275. Largest Combination With Bitwise AND Greater Than Zero
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

## solution
```c++
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        //  [16,17,71,62,12,24,14]
        //      0010000     16
        //      0010001     17
        //      1000111     71
        //      0111110     62
        //      0001100     12
        //      0011000     24
        //      0001110     14
        //     {1,1,4,4,4,3,2}
        // 10000000 = 0000 0001 0110 1001 0001 1001
        // 
        // 找出最大的數字
        vector<int> vec(31,0);
        int ret = 0;
        for(int i=30;i>-1;i--){
            for(int c:candidates){
                if( (c>>i)&1==1 ) vec[30-i]++;
            }
            ret = max(ret, vec[30-i]);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`