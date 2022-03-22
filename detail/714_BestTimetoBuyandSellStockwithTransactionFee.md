---
title: 714. Best Time to Buy and Sell Stock with Transaction Fee
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## solution

#### option 1 - dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        //sell vs. buy
        dp[0][0] = 0;
        dp[0][1] = -prices[0] -fee;
        for(int i=1;i<n;++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] );
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        }
        return dp.back()[0];
    }
};
```

#### option 2 - reduce dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        int dp_0 = 0,dp_1 = -prices[0]-fee;
        for(int i=1;i<n;++i){
            dp_0 = max(dp_0, dp_1+prices[i]);
            dp_1 = max(dp_1, dp_0-prices[i]-fee);
        }
        return dp_0;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)` `O(1)`