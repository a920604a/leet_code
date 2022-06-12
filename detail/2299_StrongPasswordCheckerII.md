---
title: 2299. Strong Password Checker II
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/strong-password-checker-ii/)

## solution
```c++
class Solution {
public:
    unordered_set<char> special = {
        '!','@','#','$','%','^','&','*','(',')','-','+'
    };
    bool Rule1(string password){
        return password.size()>7;
    }
    bool Rule2(string password){
        for(char c:password){
            if(c>='a' && c<='z') return true;
        }
        return false;
    }
    bool Rule3(string password){
        for(char c:password){
            if(c>='A' && c<='Z') return true;
        }
        return false;
    }
    bool Rule4(string password){
        for(char c:password){
            if(c>='0' && c<='9') return true;
        }
        return false;
    }
    bool Rule5(string password){
        for(char c:password){
            if(special.count(c)) return true;
        }
        return false;
    }
    bool Rule6(string password){
        for(int i=1;i<password.size() ; ++i){
            if(password[i] == password[i-1]) return false;
        }
        return true;
    }
    
    
    bool strongPasswordCheckerII(string password) {
        bool ret = true;
        ret &= Rule1(password);
        ret &= Rule2(password);
        ret &= Rule3(password);
        ret &= Rule4(password);
        ret &= Rule5(password);
        ret &= Rule6(password);
        return ret;
        
        
    }
};
```
