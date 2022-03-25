---
title: 8. String to Integer (atoi)
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/string-to-integer-atoi/)

## solution
```c++
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') i++;
        int flag = 1;
        if(s[i] == '-' || s[i] == '+'){
            
            if(s[i] =='-') flag = -1;
            i++;
        }
        int ret = 0;
        for(int j = i;j<s.size() ; ++j){
            if(s[j]-'0' >=0 && s[j]-'0'<=9){
                if(ret>INT_MAX/10 || (ret==INT_MAX/10 && s[j]-'0'>INT_MAX%10)){
                    return flag==1?INT_MAX:INT_MIN;
                }
                ret*= 10;
                ret += s[j]-'0';
            }
            else break;
        }
        return ret*flag;
    }
};
```
## analysis
- time complexity `O(n)` 
- space compleity `O(n)`