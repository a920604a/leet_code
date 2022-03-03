---
title: 518. Coin Change 2
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/coin-change-2/)


## solution
#### option 1 - dp
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        // 有多少種方法(硬幣組合)可以兌換 amount元
        //  0   1   2   3   4   5
        //  0   0   0   0   0   0
        //1 1   1   1   1   1   1
        //2 1   1   2   2   3   3
        //5 1   1   2   2   3   4
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
        for(int i=1;i<n+1;++i) dp[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j >= coins[i-1]) dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]] ;
                else dp[i][j] = dp[i-1][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp.back().back();   
    }
};
```


#### option 2 - reduce dp

```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        // 有多少種方法(硬幣組合)可以兌換 amount元
        //  0   1   2   3   4   5
        //  0   0   0   0   0   0
        //1 1   1   1   1   1   1
        //2 1   1   2   2   3   3
        //5 1   1   2   2   3   4
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j >= coins[i-1]) dp[j] += dp[j-coins[i-1]];

            }
        }
        return dp.back(); 
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`