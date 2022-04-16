---
title: 62. Unique Paths
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/unique-paths/)


## solution

#### option 1 - dp
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        //  1   1   1   1   1   1   1   
        //  1   2   3   4   5   6   7   
        //  1   3   6   10  15  21  28
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

#### option 2 - reduce dp
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        //  1   1   1   1   1   1   1   
        //  1   2   3   4   5   6   7   
        //  1   3   6   10  15  21  28
        vector<int> dp(n,1);
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[j] += dp[j-1];
            }
        }
        return dp.back();
    }
};
```
```c
int uniquePaths(int m, int n){
    int *dp = malloc(sizeof(int)*n);
    //  0   1   1   1   1   1   1
    //  1   2   3   4   5   6   7   
    //  1   3   6   10  15  21  28
    
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i==0 && j==0) *(dp+j) = 1;
            else if(i==0 || j==0) *(dp+j) = 1;
            else *(dp+j) += *(dp+j-1);
        }
    }
    return *(dp+n-1);
}
```
#### option 3 use math
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *=( m + n - 1 - i);
            denom *= i;
        }
        return (int)(num / denom);
    }
};
```
## analysis
- option 1
    - time complexity `O(n*m)`
    - space complexity `O(n*m)`
- option 2
    - time complexity `O(n*m)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`