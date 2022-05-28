---
title: 2283. Check if Number Has Equal Digit Count and Digit Value
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/)
## solution
```c++
class Solution {
public:
    bool digitCount(string num) {
        vector<int> his(10,0);
        for(char c:num) his[c-'0']++;
        for(int i=0;i<num.size();++i){
            if(his[i] != num[i]-'0') return false;
        }
        return true;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`