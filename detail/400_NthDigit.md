---
title: 400. Nth Digit
tags:
    - Math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/nth-digit/)

## solution
```c++
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        // 先定位要去哪個區間找尋答案 [1,9] [10,99] [100,999] [1000,9999]
        //                          1個位數*9個   2個位數*90個 ...
        while(n> len*cnt){
            n-= len*cnt;
            len++;
            cnt *=10;
            start *=10;
            
        }
        start += (n-1)/len;
        // 答案在這數字裡
        string t = to_string(start);
        return t[(n-1)%len]-'0';
        
    }
};
```

