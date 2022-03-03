---
title: 712. Minimum ASCII Delete Sum for Two Strings

tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)


## solution
```c++
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        //      e   a   t   
        //      101 198 314
        //s 115
        //e 216
        //a 313
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1;i<n+1 ;i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j=1;j<m+1;j++) dp[0][j] = dp[0][j] = dp[0][j-1] + s2[j-1];
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j] + s1[i-1] ,dp[i][j-1] + s2[j-1]) ;
            }
        }
        return dp.back().back();
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`

