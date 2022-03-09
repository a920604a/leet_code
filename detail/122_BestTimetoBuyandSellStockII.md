---
title: 122. Best Time to Buy and Sell Stock II
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1;i<prices.size(); ++i){
            profit+=max(prices[i]-prices[i-1], 0);
        }
        return profit;
    }
};
```
## analysis 
- time complexity `O(n)`
- space complexity `O(1)`