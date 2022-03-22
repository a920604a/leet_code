---
title: 122. Best Time to Buy and Sell Stock II
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - greedy
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

#### option 2 - dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        // sell vs. hold
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<n;++i){
            // 要麻今天休息，要買今天賣掉
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // 要麻今天休息，要嘛今天買進
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp.back()[0];
    }
};
```
#### option 3 - reduce dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i=1;i<n;++i){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1+prices[i]);
            dp_1 = max(dp_1, temp-prices[i]);
        }
        return dp_0;
    }
};
```
## analysis 
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(1)`
    


