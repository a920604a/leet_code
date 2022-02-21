---
title: 557. Reverse Words in a String III
tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

## solution
```c++
class Solution {
public:
    void reverse(string &s, int l, int r){
        while(l<r) swap(s[l++], s[r--]);        
    }
    string reverseWords(string s) {
        int l =0, r =0;
        int n = s.size();
        while(r<n){
            while(l<n && s[l]==' ') l++;
            r = l+1;
            while(r<n && s[r]!=' ') r++;
            reverse(s, l, r-1);
            l = r+1;
        }
        return s;
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
