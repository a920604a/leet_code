---
title: 1137. N-th Tribonacci Number
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/n-th-tribonacci-number/)


## solution

- recursive => time out
```c++
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
    }
};
```
#### option 1 - memo pattern
```c++
class Solution {
public:
    unordered_map<int,int > ans;
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(ans.find(n)!=ans.end()) return ans[n];
        ans[n] =  tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        return ans[n];
    }
};
```
#### option 2 - dp
```c++
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = dp[2] = 1;
        for(int i=3;i<=n;++i) dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        return dp[n];
    }
};

```

#### option 3 - reduce dp 

```c++
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int a= 0, b =1, c=1, d;
        for(int i=3;i<=n;++i){
            d = a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};

```
## analysis

- option 2 - dp
  - time complexity `O(n)`
  - space complexity `O(n)`

- option 3 
  - time complexity `O(n)`
  - space complexity `O(1)`