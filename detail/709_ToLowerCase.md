---
title: 709. To Lower Case
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/to-lower-case/)

## solution
```c++
class Solution {
public:
    string toLowerCase(string s) {
        string str;
        for(char c: s){
            if(c>='A' && c<='Z') c+=32;
            str+=c;
        }
        return str;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`

