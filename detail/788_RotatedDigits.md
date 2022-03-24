---
title: 788. Rotated Digits
tags:  
    - dp
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rotated-digits/)

## solution 
#### option 1
```c++
class Solution {
public:
    bool check(int k){
        string str = to_string(k);
        bool flag = false;
        for(char c:str){
            if( c=='3' || c=='4' || c=='7') return false;
            if(c=='2' || c=='5' || c=='6' || c=='9') flag = true;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1;i<=n;++i) count+=(check(i));
        return count;
        
    }
};
```
#### option 2 - dp

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`