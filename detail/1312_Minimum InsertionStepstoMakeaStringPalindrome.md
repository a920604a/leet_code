---
title: 1312. Minimum Insertion Steps to Make a String Palindrome

tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)


## solution
```c++
class Solution {
public:
    int minInsertions(string s) {
        
        //  m   b   a   d   m
        //
        //m 0   1   2   3   2
        //b     0   1   2   3
        //a         0   1   2 
        //d             0   1
        //m                 0
        
        // if(s[i]!=s[j]) dp[i][j] = 1+min(dp[i+1][j], dp[i][j-1]);
        int n =s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-2;i>-1;--i){
            for(int j = i+1;j<n;++j){
                // 形成回文
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                // 插入
                else dp[i][j] = 1 + min(dp[i+1][j] ,dp[i][j-1]);
            }
        }
        return dp[0].back();
        
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`