---
title: 509. Fibonacci Number
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/fibonacci-number/)


## solution


#### option 1 - recursive

```c++
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);      
    }
};
```

#### option 1.1 memo pattern
```c++
class Solution {
public:
    unordered_map<int,int> ans;
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(ans.find(n)!=ans.end()) return ans[n];
        ans[n] = fib(n-1) + fib(n-2);
        return ans[n];
    }
};
```
#### option 2 - dp
```c++
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;++i) dp[i] = dp[i-1] + dp[i-2];
        return dp.back();
    }
};
```

#### option 3 - reduce dp

```c++
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a= 0, b=1, c;
        for(int i=2;i<=n;++i){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
```
## analysis
- option 1 
  - time complexity `O(2^n)`
  - space complexity `O(1)`

- option 2
  - time complexity `O(n)`
  - space complexity `O(n)`

- option 3
  - time complexity `O(n)`
  - space complexity `O(1)`
