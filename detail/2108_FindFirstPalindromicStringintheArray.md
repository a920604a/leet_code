---
title: 2108. Find First Palindromic String in the Array
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)

## solution

```c++
class Solution {
public:
    bool isPalindrome(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l++] !=s[r--]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word:words){
            if(isPalindrome(word)) return word;
        }
        return "";
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`