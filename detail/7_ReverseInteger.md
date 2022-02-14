# 7. Reverse Integer

###### tags: `leetcode` `Bit Manipulation` 

## [problem](https://leetcode.com/problems/reverse-integer/)

## solution


```c++
class Solution {
public:
    int reverse(int x) {
        
        int ret = 0;
        while(x){
            if(abs(ret) > INT_MAX/10) return 0;
            ret = 10*ret + (x%10);
            x/=10;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`


