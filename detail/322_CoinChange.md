---
title: 322. Coin Change

tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/coin-change/)

給定一組整數陣列`coins`，表示不同面額的硬幣，一個整數`amount`，請問最少硬幣數，可以組成`amount`元，如果不行`return -1`

## solution
> 至少四種作法
> 1. brute force, backtracking
> 2. backtracking + memo pattern
> 3. dp
> 4. reduce dp

- `base case` 面額0元，不需硬幣數，所以為0。
- 遍歷`coins`，不斷尋找是否可以更新更小硬幣數

#### option 1

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 要湊出amount 元最少需要幾個硬幣
        //      0   1   2   3   4   5   6   7   8   9   10  11
        //      12  12  12  12  12  12  12  12  12  12  12  12  
        //1     0   1   2   3   4   5   6   7   8   9   10  11
        //2     0   1   1   2   2   3   3   4   4   5   5   6
        //5     0   1   1   2   2   1   2   2   3   3   2   3
        
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, amount+1));
        // base case 
        for(int i=0;i<n+1;++i) dp[i][0] = 0;
        for(int i=1;i<n+1;++i){
            for(int j=1;j<amount+1;++j){
                if(j>=coins[i-1]) dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount]==amount+1?-1:dp[n][amount];      
        
    }
};
```

#### option 2 reduce dp

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //      0   1   2   3   4   5   6   7   8   9   10  11
        //      12  12  12  12  12  12  12  12  12  12  12  12  
        //1     0   1   2   3   4   5   6   7   8   9   10  11
        //2     0   1   1   2   2   3   3   4   4   5   5   6
        //5     0   1   1   2   2   1   2   2   3   3   2   3
        
        
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        // base case 
        dp[0] = 0;
        for(int i=1;i<n+1;++i){
            for(int j=1;j<amount+1;++j){
                if(j>=coins[i-1]) dp[j] = min(dp[j],1+dp[j-coins[i-1]] );
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
        
    }
};
```
## analysis
- option 1
    - time complexity `O(n^amount)`
    - space complexity `O(n^2)`
- option 2 
    - time complexity `O(n*amount)`
    - space complexity `O(n)`