# 342. Power of Four


###### tags: `leetcode` `Bit Manipulation`

## [problem](https://leetcode.com/problems/power-of-four/)

## solution

```c++
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        if((n&(n-1))!=0) return false;
        return (n&0x55555555) ==n;
    }
};
```

## analysis
- time complexity `O(1)`
- space complexity `O(1)`

