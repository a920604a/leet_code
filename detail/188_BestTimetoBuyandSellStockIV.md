---
title: 188. Best Time to Buy and Sell Stock IV
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
## solution
```c++
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        if (k > n / 2)
            return maxProfit(prices);
        // 因為一次買入和賣出，至少需要兩天，所以k應該不超過n/2。如果超過就相當於沒有約束，相當於k=+infinity

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2,0)));
        for(int i = 0;i<n;++i){
            for(int t=k;t>=1;t--){
                if(i==0){
                    dp[i][t][0] = 0;
                    dp[i][t][1] = -prices[i];
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
#### option 2
```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // https://www.programcreek.com/2014/03/leetcode-best-time-to-buy-and-sell-stock-iv-java/
        if(prices.size() < 2 || k<=0) return 0;
        int n= prices.size();
        vector<int> local (k+1,0), global(k+1,0);
        for(int i=0;i<n-1;i++){
            int diff = prices[i+1] - prices[i];
            for(int j = k;j>=1;j--){
                local[j] = max(global[j-1]+ max(diff, 0), local[j]+diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
};
```
## analysis 
- time complexity `O(n)`
- space complexity `O(n)`