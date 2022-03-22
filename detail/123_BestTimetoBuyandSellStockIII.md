---
title: 123. Best Time to Buy and Sell Stock III
tags:
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
## solution
#### option 1 - dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size(), k=2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2,0)));
        for(int i=0;i<n;++i){
            for(int t = k;t>=1;--t){
                if(i==0){
                    dp[i][t][0] = 0;
                    dp[i][t][1] = -prices[0];
                    continue;
                }
                dp[i][t][0] = max(dp[i-1][t][0], dp[i-1][t][1] + prices[i]);
                dp[i][t][1] = max(dp[i-1][t][1], dp[i-1][t-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
```

#### option 2 - reduce dp

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int dp_i10 = 0, dp_i11 = INT_MIN;
        int dp_i20 = 0, dp_i21 = INT_MIN;
        for (int price : prices) {
            dp_i20 = max(dp_i20, dp_i21 + price);
            dp_i21 = max(dp_i21, dp_i10 - price);
            dp_i10 = max(dp_i10, dp_i11 + price);
            dp_i11 = max(dp_i11, -price);
        }
        return dp_i20;
        
        
    }
};
```

#### option 3 
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2) return 0;
        int n= prices.size();
        vector<int> left(n,0), right(n,0);
        left[0] = 0, right[n-1] = 0;        
        //      3   3   5   0   0   3   1   4
        //mn    3   3   3   0   0   0   0   0
        //left  0   0   2   2   2   3   3   4
        //mx    5   5   5   5   4   4   4   4
        //right 4   4   4   4   4   3   3   0
        // 雙向夾擠
        int mn = prices[0], mx = prices[n-1];
        for(int i=1;i<n;++i){
            mn = min(mn, prices[i]);
            left[i] = max(left[i-1], prices[i] - mn);
        }
        for(int i= n-2;i>-1;--i){
            mx = max(mx, prices[i]);
            right[i] = max(right[i+1], mx - prices[i]);
        }
        int profit = 0;
        for(int i=0;i<n;++i) profit = max(profit, left[i] + right[i]);
        return profit;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(n)`