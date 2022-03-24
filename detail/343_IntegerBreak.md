---
title: 343. Integer Break
tags:  
    - dp
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/integer-break/)
## solution
- backtracking
```c++
class Solution {
public:
    int ret;
    void dfs(int k, int t, int prod){
        if(t==0){
            ret = max(ret, prod);
            return;
        }
        if(t<0) return ;
        for(int i=1;i<k;++i){
            dfs(k,t-i, prod*i);
        }
        
    }
    int integerBreak(int n) {
        
        ret = 1;
        int prod =1;
        dfs(n,n,prod);
        return ret;
        
    }
};
```

#### option 1 - dp
```c++
class Solution {
public:
    int integerBreak(int n) {
        
        //  2   3   4   5   6   7   8   9   10
        //  1   2   4   6   9   12  18  27  36
        
        vector<int> dp(n+1,1);
        for(int i=3;i<=n;++i){
            for(int j =1;j<i;++j){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
```
#### option 2 - Math
```c++
class Solution {
public:
    int integerBreak(int n) {
        
        // 可以看出從5開始，數字都需要先拆出所有的3，一直拆到剩下一個數為2或者4
        if(n==2 || n==3) return n-1;
        int ret = 1;
        while(n>4){
            ret*=3;
            n-=3;
        }
        return ret*n;
        
    }
};
```
## analysis
- option 1
    - time complexity `O(n^2)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`