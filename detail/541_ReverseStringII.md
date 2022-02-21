---
title: 541. Reverse String II
tags:  
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/reverse-string-ii/)

## solution
```c++
class Solution {
public:
    void reverse(string& s, int l, int r ){
        while(l<r) swap(s[l++], s[r--]);
    }
    string reverseStr(string s, int k) {
        for(int i =0;i<s.size() ; i+=2*k){
            reverse(s, i, min(i+k-1, int(s.size()-1)));
        }
        return s;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`