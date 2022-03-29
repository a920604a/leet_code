---
title: 389. Find the Difference

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-difference/)

給定兩字串，字串t比字串s多出一個字元，將他找出來

## solution

- 逐一字串 t 拜訪，拜訪到的字元將轉其對應ASCII 取值，並累加
- 逐一字串 s 拜訪，拜訪到的字元將轉其對應ASCII 取值，並相減

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for(char c:t) ret +=c; // auto cast
        for(char c:s) ret -=c; 
        return (char)ret;
    }
};
```
- 遍歷字串s,t，對所有字元做xor

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret =0;
        for(char c:t) ret ^=c;
        for(char c:s) ret ^=c; 
        return ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
