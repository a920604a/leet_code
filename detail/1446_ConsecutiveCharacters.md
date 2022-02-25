---
title: 1446. Consecutive Characters
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/consecutive-characters/)

## solution
```c++
class Solution {
public:
    int maxPower(string s) {
        int count = 1, ret= 1, n =s.size();
        char val = s[0];
        for(int i=1;i<n;++i){
            if(val == s[i]){
                count++;
            }
            else{
                ret = max(ret,count);
                count =1;
                val = s[i];
            }
        }
        ret = max(ret,count);
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
