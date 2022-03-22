---
title: 121. Best Time to Buy and Sell Stock

tags:  
    - dp
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

從股票價位陣列中找出，可以最大化淨利



## Solution

#### option 1
- 維護一個dp 紀錄歷史至今最低價位，在用當天股價減去至今最低點，並更新ret

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //      7   1   5   3   6   4
        //mn    7   1   1   1   1   1
        int n = prices.size();
        vector<int> mn(n,INT_MAX);
        mn[0] = prices[0];
        for(int i=1;i<n;++i) mn[i] = min(mn[i-1], prices[i]);
        int ret = 0;
        for(int i =1;i<n;++i){
            ret = max(prices[i] - mn[i], ret);
        }
        return ret;   
    }
};
```
#### option 2 - algo
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, ret = INT_MIN;
        for(int p:prices){
            mn = min(mn, p);
            ret = max(ret, p-mn);
        }
        return ret;
    }
};
```
#### option 3 - dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector(2,0));
        // sell it 
        dp[0][0] = 0;
        // hold it
        dp[0][1] =-prices[0];
        // 第一次持有因沒有錢需要借錢所以為負
        //      sell    hold
        //7     0       -7
        //1     0       -1    
        //5     4       -1
        //3     4       -1
        //6     5       -1
        //4     5       -1
        for(int i=1;i<n;++i){
            // 賣掉，要麻今天休息，要嘛是今天選擇賣掉，我手頭上持有的現金
            dp[i][0]= max(dp[i-1][0], dp[i-1][1] + prices[i]);
            // 持有，要嘛今天休息，或是今天選擇買進，手頭上持有的現金
            dp[i][1]= max(dp[i-1][1],  -prices[i]);
        }
        return dp.back()[0];
    }
};
```
#### option 4 - reduce dp
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i=1;i<n;++i){
            int temp = dp_1;
            dp_0 = max(dp_0, dp_1+prices[i]);
            dp_1 = max(dp_1, -prices[i]);
        }
        return dp_0;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - speed complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 3 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 4
    - time complexity `O(n)`
    - space complexity `O(1)`