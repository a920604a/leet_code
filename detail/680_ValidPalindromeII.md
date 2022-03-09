---
title: 680. Valid Palindrome II
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/valid-palindrome-ii/)


## solution

```c++
class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return isPalindrome(s, l+1,r) || isPalindrome(s, l,r-1);
            l++;
            r--;
        }
        return true;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`