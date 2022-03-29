---
title: 70. Climbing Stairs

tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/climbing-stairs/)



## solution

#### option 1
```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        if(n<2) return n;
        dp[0] = 1, dp[1] = 1;
        for(int i=2;i<=n;++i){
            dp[i] = dp[i-1] +dp[i-2];
        }
        return dp.back();   
    }
};
```
- recursive version => time out
```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        return climbStairs(n-1)+climbStairs(n-2);
        
    }
};
```
- optimal recursive version

使用 hash table 紀錄已經call 過的function()，避免重複運算
```c++
class Solution {
public:
    unordered_map<int,int> mp;
    int climbStairs(int n) {
        if(n<3) return n;
        if(mp.count(n)) return mp[n];
        mp[n] = climbStairs(n-1) + climbStairs(n-2);
        return mp[n];     
        
    }
};
```

#### option 2 - reduce space
```c++
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int a = 1, b= 2,c = 0;
        for(int i=3;i<=n;++i){
            c= a+b;
            a=b;
            b=c;
        }
        return c;
    }
};

```

## analysis
- option 1 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`