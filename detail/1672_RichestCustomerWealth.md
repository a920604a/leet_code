---
title: 1672. Richest Customer Wealth
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/richest-customer-wealth/)


## solution
```c++
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = 0, n= accounts.size();
        for(int i=0;i<n;++i){
            int temp = 0;
            for(auto a:accounts[i]) temp+=a;
            mx = max(mx, temp);
        }
        return mx;
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(1)`