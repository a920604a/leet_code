---
title: 409. Longest Palindrome
tags:
    - hash table
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-palindrome/)

## solution 
```c++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        for(char c:s){
            if(!st.count(c)) st.insert(c);
            else st.erase(c);
        }
        if(st.size()>0) return s.size()- st.size() +1;
        else return s.size();
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`
