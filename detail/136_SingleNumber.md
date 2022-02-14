# 136. Single Number

###### tags: `leetcode` `Bit Manipulation`

## [problem](https://leetcode.com/problems/single-number/)

- 從一維陣列找出不重複的數字，假設其他數字皆會出現兩次

## solution
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
