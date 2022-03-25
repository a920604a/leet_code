---
title: 58. Length of Last Word
tags:  
    - Math
categories: leetcode
comments: false
---

## [prolem](https://leetcode.com/problems/length-of-last-word/)
## solution
#### option 1 
```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int l =-1 , r = s.size()-1;
        while(r >l && s[r]==' ') r--;
        for(int i=0;i<=r;  ++i){    
            if(s[i] ==' ') l = i;
        }
        if(l==-1) return r+1;
        return r-l;
    }
};
```
#### option 2 
```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int r= s.size()-1;
        while(r>-1 && s[r]==' ') r--;
        if(r==-1) return 0;
        for(int i=r;i>-1;i--){
            if(s[i] == ' ') return r-i;
        }
        return r+1;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`