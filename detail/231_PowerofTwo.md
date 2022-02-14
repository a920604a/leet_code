# 231. Power of Two

###### tags: `leetcode` `Bit Manipulation`

## [problem](https://leetcode.com/problems/power-of-two/)

## solution

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1)) ==0;
    }
};
```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`

