---
title: 516. Longest Palindromic Subsequence
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-palindromic-subsequence/)


## solution

```c++
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ret = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        //  b   b   b   a   b
        //b 1   2   3   3   4
        //b     1   2   2   3
        //b         1   1   3
        //a             1   1
        //b                 1
        
        for(int i=0;i<n;++i) dp[i][i] =1;
        
        for(int i=n-2;i>-1;i--){
            for(int j=i+1 ; j<n;++j){
                if(s[i] == s[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0].back();
    }
};
```

- reduce dp

## analysis

- time complexity `O(nm)`
- space complexity `O(nm)`
