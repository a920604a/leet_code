---
title: 1299. Replace Elements with Greatest Element on Right Side
tags: 
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)

## solution
```c++
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // 從右至左找最大
        int n = arr.size();
        vector<int> ret(n, -1);
        //  17  18  5   4   6   1
        //  18  6   6   6   1   -1
        int mx = arr.back();
        for(int i=n-2;i>-1;--i){
            ret[i] = mx;
            mx = max(mx, arr[i]);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`