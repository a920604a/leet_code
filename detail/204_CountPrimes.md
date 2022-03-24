---
title: 204. Count Primes
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-primes/)


## solution
Sieve of Eratosthenes
#### option 1 - dp
```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1, true);
        for(int i=2;i<sqrt(n);++i){
            if(primes[i]){
                for(int j = 2;i*j<=n;++j){
                    primes[j*i] = false;
                }
                // faster
                // for(int j= i*i;j<n;j+=i) primes[j] = false;
            }
            
        }
        int count = 0;
        for(int i=2;i<n;++i) count+=primes[i];
        return count;
    }
};
```


## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`