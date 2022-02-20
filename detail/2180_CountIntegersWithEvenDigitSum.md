---
title: 2180. Count Integers With Even Digit Sum
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/)


## solution

```c++
class Solution {
public:
    bool isEvenDigit(int n){
        int digit = 0;
        while(n){
            digit+=(n%10);
            n/=10;
        }
        return digit%2==0;
    }
    int countEven(int num) {
        // option 1  brute force time complexity O(n^2)
        int count=0;
        for(int i=1;i<=num;++i){
            count+= isEvenDigit(i)?1:0;
        }
        return count;
        
    }
};
```
## analysis
- time complexity `O(nlogn)`
- speed complexity `O(1)`