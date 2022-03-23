---
title: 221. Maximal Square
tags: 
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximal-square/)
## solution
```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int>(m,0));
        int ret = 0;
        for(int i =0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j] == '0') continue;
                else if(i== 0 || j==0) dp[i][j] = matrix[i][j]  - '0';
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                ret = max(ret, dp[i][j]);
            }
        }
        return ret*ret;
        
    }
};
```
## analysis
- time complexity `O(n*n)`
- space complexity `O(n*n)`
