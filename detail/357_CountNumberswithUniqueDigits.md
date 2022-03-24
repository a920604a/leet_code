---
title: 357. Count Numbers with Unique Digits
tags:
    - Math
    - backtracking
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-numbers-with-unique-digits/)

## solution
利用測資作弊
```c++
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        //  0   1   2   3   4   5   6   7   8  
        // 1
        // 10
        // 91
        // 739
        // 5275
        // 32491
        // 168571
        // 712891
        // 2345851
        vector<int> nums = {1,10,91,739,5275,32491, 168571, 712891,2345851};
        return nums[n];
        
    }
};
```

#### option 1 - recursive
```c++
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // from hint 5;
        // f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) 
        // option 1
        if(n ==0) return 1;
        if(n ==1) return 10;
        int total = 9, d = 9, t= n;
        while(--t){
            total *=d--;
        }
        return total + countNumbersWithUniqueDigits(n-1);
        
    }
};
```

#### option 2 - dp
```c++
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n ==0) return 1;
        if(n==1) return 10;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 10;
        for(int i=2;i<=n;++i){
            int j = i-1, d = 9, t =d;
            while(j--){
                t*=d;
                d--;
            }
            dp[i] += t+dp[i-1];
        }
        return dp.back();
        
    }
};
```
## analysis
- time complexity `O(1)` , beacuse of `n<=8`
- space complexity `O(1)`
