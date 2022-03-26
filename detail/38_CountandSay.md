---
title: 38. Count and Say
tags:  
    - backtracking
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-and-say/)
## solution

#### option 1 iterative
```c++
class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for(int i=1;i<n;++i){
            string path ;
            int count = 1, val = ret[0];
            for(int j=1;j<ret.size() ; ++j){
                if(ret[j] == val) count++;
                else{
                    path+=to_string(count);
                    path+=val;
                    count = 1;
                    val = ret[j];
                }
            }
            if(count > 0) {path+=to_string(count);path+=val;}
            ret = path;
        }
        return ret;
    }
};
```
#### option 2 recursive
```c++

```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(nm)`
