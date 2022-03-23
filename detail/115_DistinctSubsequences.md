---
title: 115. Distinct Subsequences
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/distinct-subsequences/)
## solution
```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        // 不能刪除t字串 所以不會有 dp[i-1][j]
        //      r   a   b   b   i   t
        //  1   0   0   0   0   0   0
        //r 1   1   0   0   0   0   0      
        //a 1   1   1   0   0   0   0
        //b 1   1   1   1   0   0   0
        //b 1   1   1   2   1   0   0
        //b 1   1   1   3   3   0   0
        //i 1   1   1   3   3   3   0
        //t 1   1   1   3   3   3   3
        
        int n = s.size(),  m = t.size(), mod = 1e+9;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n+1 ; ++i) dp[i][0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                // 當字元相同時， 刪除s字串的方法數 加上 替換的方法數
                if(s[i-1] == t[j-1]) dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] )%mod ;
                // 當字元不同時，刪除s字串的方法數
                else dp[i][j] = dp[i-1][j] %mod;
            }
        }
        return dp[n][m];
        
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`