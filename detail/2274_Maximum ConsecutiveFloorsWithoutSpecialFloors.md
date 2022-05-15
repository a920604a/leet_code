---
title: 2274. Maximum Consecutive Floors Without Special Floors
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/)

## solution
```c++
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ret = 0;
        special.insert(special.begin(), bottom-1);
        special.push_back(top+1);
        int n =special.size() ;
        for(int i=1;i<n;++i) ret = max(ret, special[i]-special[i-1]-1);
        return ret;  
    }
};
```

## analysis
- time complexity `O(mligm)` m is the legth of `vector<int>& special`
- sparse complexity `O(1)`