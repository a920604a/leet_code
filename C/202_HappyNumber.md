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
        //  2 -> 4  -> 16 ->  37 -> 58  -> 89 ->145 -> 42 -> 20 -> 4
        int m = n;
        unordered_set<int> history;
        history.insert(m);
        while(1){
            int sum = 0;
            while(m){
                sum+=pow(m%10,2);
                m/=10;
            }
            if(sum==1) return true;
            m = sum;
            if(history.find(sum)!=history.end()) return false;
            history.insert(sum);
            
        }
        return true;
        
    }
};
```
## analysis
