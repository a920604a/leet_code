---
title: 202. Happy Number
tags: 
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/happy-number/)


## solution

```c++
class Solution {
public:
    bool isHappy(int n) {
        // 19 -> 82 -> 68 -> 100 -> 1
        //  2 -> 4  -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
        int happy = n;
        unordered_set<int> s({happy});
        while(happy!=1){
            int m=0;
            while(happy){
                m+=(happy%10)*(happy%10);
                happy/=10;
            }
            happy = m;
            if(s.find(happy)!=s.end()) return false;
            s.insert(happy);
        }
        return true;
        
    }
};
```
## analysis
