---
title: 120. Triangle
tags:  
    - dp
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/triangle/)

## solution
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //  2                   2
        //  3   4               5   6
        //  6   5   7           11  10  13
        //  4   1   8   3       15  11  18  16
        
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ret = INT_MAX;
        dp[0][0] = triangle[0][0] ;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i; j++){
                if(j==0) dp[i][j] = triangle[i][j] + dp[i-1][j];
                else if(j==i) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                else dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                if(i==n-1) ret = min(dp[i][j], ret);
            }
        }
        return ret;
    }
};
```


#### option 2 - in-place modify
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //  2                   2
        //  3   4               5   6
        //  6   5   7           11  10  13
        //  4   1   8   3       15  11  18  16
        
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        int ret = INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i; j++){
                if(j==0) triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                else if(j==i) triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
                else triangle[i][j] = triangle[i][j] + min(triangle[i-1][j-1], triangle[i-1][j]);
                if(i==n-1) ret = min(triangle[i][j], ret);
            }
        }
        return ret;
    }
};
```
#### option 3 - follow up
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for(int i=(int)triangle.size()-2;i>-1 ; i--){
            for(int j =0;j<=i; ++j){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(nm)` `O(1)` in-place `O(n)`