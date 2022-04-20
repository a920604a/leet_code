---
title: 583. Delete Operation for Two Strings
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/delete-operation-for-two-strings/)


## solution
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        
       //      e   a   t
        //  0   1   2   3
        //s 1   2   3   4
        //e 2   1   2   3
        //a 3   2   1   2
        
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<n+1;++i) dp[i][0] = i;
        for(int j=0;j<m+1;++j) dp[0][j] = j;
        for(int i=1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(word1[i-1] !=word2[j-1]) dp[i][j] = min( dp[i-1][j],dp[i][j-1] ) +1; // insert or delete
                else dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp.back().back();
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`

