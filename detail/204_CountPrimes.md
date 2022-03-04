---
title: 204. Count Primes
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-primes/)


## solution
#### option 1 - dp
```c++
class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool> primes(n+1, false);
        for(int i=2;i*i<n;++i){
            if(primes[i]==false){
                for(int j=2;i*j<=n;++j) primes[i*j] = true;

                // faster
                // for(int j= i*i;j<n;j+=i) primes[j] = true;
            }
        }
        int count =0;
        for(int i=2;i<n;++i) count+=(primes[i]==false);
        return count;
    }
};
```


## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`