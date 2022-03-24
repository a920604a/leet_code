---
title: 372. Super Pow
tags:  
    - Math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/super-pow/)
## solution
```c++
class Solution {
public:
    int mod = 1337;
    int myPow(int a, int k){
        a = a%mod;
        int ret =1;
        for(int i=0;i<k ; ++i) ret = (ret*a) %mod;
        return ret;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int x = b.back();
        b.pop_back();
        int part1 = myPow(a,x);
        int part2 = myPow(superPow(a,b),10);
        return part1 *part2%mod;
        
    }
};
```
