---
title: CountSemiprimes
categories: 
    - codility
    - Sieve of Eratosthenes
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/)

## solution
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include<math.h>
vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    if(N==1) return {0};
    // create [1, N] ]vector using Sieve of Eratosthenes
    vector<int> dp(N+1, false);
    dp[1] = dp[0] = true;
    for(int i =2;i<=sqrt(N) ; ++i){
        if(dp[i] == false){
            for(int j=2;i*j <=N ; ++j) dp[i*j] = true;
        }
    }
    vector<int> primes;
    for(int i=2;i<N+1 ; ++i){
        if(dp[i] == false) primes.push_back(i);
    }
    // for(int d:primes) cout<<d<<" ";
    // cout<<endl;
    vector<int> semiprime;
    for(int i=0;i<primes.size();++i) {
        for(int j = i;j<primes.size() ; ++j){
            // if(primes[i< * primes[j]=Ｎ);
            if(primes[i]*primes[j] > N) break;
            semiprime.push_back(primes[i]*primes[j]);
        }
    }
    sort(semiprime.begin(), semiprime.end());
    // for(int s:semiprime) cout<<s<<" ";
    // create prefix sum
    vector<int> prefix(N+1, 0);
    //  4   6   9   10  14  15  21  22  25  26

    //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  
    //  0   0   0   0   1   1   2   2   2   3   4   4   4   4   5   6   6   6   6   6   6   7   8   8   8   9   10
    int j = 0, cur = 0;
    for(int i=0;i<N+1 ; ++i){
        if(i == semiprime[j]){
            ++j;
            prefix[i] = ++cur;
        }
        prefix[i] = cur;
    }
    // cout<<endl;
    // for(int p:prefix) cout<<p<<" ";
    vector<int>ret;
    for(int i=0;i<P.size() ; ++i){
        ret.push_back(prefix[Q[i]] - prefix[P[i]-1]);

    }
    return ret;


}
```
## analysis
- time complexity `O(n^2)`
- speed complexity `O(n)`