---
title: 2119. A Number After a Double Reversal

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/a-number-after-a-double-reversal/)



## solution

```c++
class Solution {
public:
    int reverse(int num){
        int ret = 0;
        while(num){
            ret*=10;
            ret+=(num%10);
            num/=10;
        }
        cout<<ret<<endl;
        return ret;
    }
    bool isSameAfterReversals(int num) {
        return reverse(reverse(num)) == num;
        
    }
};
```
## analyze
- time complexity `O(1)` 
- space complexity `O(1)`
