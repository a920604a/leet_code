---
title: 401. Binary Watch
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-watch/)


## solution 
```c++
class Solution {
public:
    int count(int n){
        int ret = 0;
        while(n){
            n &= (n-1);
            ret++;
        }
        return ret;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for(int h = 0;h<12;++h){
            for(int m = 0;m<60 ;++m){
                int account = (h<<6)+m;
                if(count(account) == turnedOn){
                    string cand  = to_string(h);
                    if(m<10) cand +=":0";
                    else cand += ":";
                    cand += to_string(m);
                    ret.push_back(cand);           
                }
            }
        }
        return ret;      
    }
};
```

## analysis
- time complexity `O(60*12)`
- space complexity `O(n)`
