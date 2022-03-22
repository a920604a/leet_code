---
title: 309. Best Time to Buy and Sell Stock with Cooldown
tags:
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
## solution
#### option 1 - dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0 ;
        vector<vector<int>> dp(n, vector<int>(2,0));
        // sell vs. hold
        dp[0][0]= 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], prices[1]+dp[0][1]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        for(int i=2;i<n;++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp.back()[0];
    }
};
```

#### option 2 - reduce dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int dp_pre_0 = 0; // 代表 dp[i-2][0]
        for (int i = 0; i < n; ++i)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
        
    }
};

```

## analysis
- time complexity `O(n)`
- space complexity `O(n)` `O(1)`