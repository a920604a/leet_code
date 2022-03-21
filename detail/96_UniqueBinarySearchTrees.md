---
title: 96. Unique Binary Search Trees
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/unique-binary-search-trees/)
## solution
#### option 1 - dfs + memo
memo pattern
```c++
class Solution {
public:
    vector<vector<int>> memo;
    int numTree(int l,  int r){
        if(l>r) return 1;
        if(memo[l][r]!= -1) return memo[l][r];
        int count = 0 ;
        for(int i=l;i<=r;++i){
            int root = i;
            int left = numTree(l,root-1);
            int right = numTree(root+1,r);
            count+=left*right;
        }
        return memo[l][r] = count;
    }
    int numTrees(int n) {
        memo = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return numTree(1,n);
    }
};
```
#### option 2 - dp
```c++
class Solution {
public:
    int numTrees(int n) {
        // dp
        //  1   2   3   4   5
        //  1   2   5   14  42
        
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<=i-1 ;++j){
                // j 左子樹區間
                dp[i]+= dp[j]*dp[i-j-1];
            }
        }
        
        return dp.back();
    }
};
```
## analysis 
- time complexity `O(n)`
- space complexity `O(n)`