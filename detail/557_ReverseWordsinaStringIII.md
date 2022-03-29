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
        int pre = 0;
        for(int i=0;i<s.size() ;++i){
            char c =s[i];
            if(c==' '){
                // reverse(s.begin()+pre, s.begin()+i);
                reverse(s, pre, i-1);
                pre = i+1;
            }
        }
        // reverse(s.begin()+pre, s.end());
        reverse(s, pre, s.size()-1);
        return s;
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
