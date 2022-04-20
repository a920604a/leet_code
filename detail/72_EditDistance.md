---
title: 72. Edit Distance

tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/edit-distance/)

## solution
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        //      r   o   s
        //  0   1   2   3
        //h 1   1   2   3   
        //o 2   2   1   2
        //r 3   2   2   2
        //s 4   3   3   2
        //e 5   4   4   3
        
        
        // word1[i]!=word[j] dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) +1;
        
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<n+1;++i) dp[i][0] = i;
        for(int j=0;j<m+1;++j) dp[0][j] = j;
        for(int i=1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(word1[i-1] !=word2[j-1]) dp[i][j] = \
                    min(
                        min(
                            dp[i-1][j],dp[i][j-1]        // insert or delete
                        ) ,
                        dp[i-1][j-1] // replace
                        ) +1;
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