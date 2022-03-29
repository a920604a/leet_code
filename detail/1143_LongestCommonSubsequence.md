---
title: 1143. Longest Common Subsequence

tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/longest-common-subsequence/)

給定兩字串，找出最長共同子序列(common subsequence)的長度

## solution


```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m =text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //      a   c   e
        //  0   0   0   0   
        //a 0   1   1   1    
        //b 0   1   1   1
        //c 0   1   2   2
        //d 0   1   2   2
        //e 0   1   2   3
        
        for(int i=1;i<n+1;++i){
            for(int j=1;j<m+1;++j){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
        
    }
};
```

## analysis
- time complexity `O(n*m)`
- space complexity `O(n*m)`