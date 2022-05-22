---
title: 2278. Percentage of Letter in String
tags:
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/percentage-of-letter-in-string/)


## solution

```c++
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count=0;
        for(char &c:s) count+=(c==letter);
        int ret=count*100/s.size();
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`