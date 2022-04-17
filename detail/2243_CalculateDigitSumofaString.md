---
title: 2243. Calculate Digit Sum of a String
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)
## solution
```c++
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            vector<string> next;
            int i ;
            for( i=0;i<s.size();i+=k){
                next.push_back(s.substr(i,min(k, (int)s.size()-i)) ) ;
            }
            s.clear();
            for(string p:next){
                int val = 0;
                for(char c:p) val +=(c-'0');
                s+=to_string(val);
            }
        }
        return s;
    }
};
```