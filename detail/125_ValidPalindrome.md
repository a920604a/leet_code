---
title: 125. Valid Palindrome

tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/valid-palindrome/)


## solution 

```c++
class Solution {
public:
    bool isValid(char &c){
        
        if(c >= '0' && c<='9') return true;
        if(c>='a' && c<='z') return true;
        if(c>='A' && c<='Z') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int l=0, r =s.size()-1;
        while(l<r){
            while(l<r && !isValid(s[l])) l++;
            while(l<r && !isValid(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
```
```c++

class Solution {
public:
    bool isValid(char c){
        if(c>='a' && c<='z') return true;
        if(c>='A' && c<='Z') return true;
        if(c>='0' && c<='9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        
        string str;
        for(char c:s){
            if(isValid(c)) str+=tolower(c);
        }
        int l=0, r = str.size()-1;
        while(l<r){
            if(str[l++] != str[r--]) return false;
        }
        return true;
        
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`