---
title: CountNonDivisible
categories: 
    - codility
    - Sieve of Eratosthenes
comments: false
---




## [problem](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/)

## solution

- [77%] time out


```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include<vector>
#include<unordered_map>
vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> v, ret;
    int n = A.size();
    for(int a:A) v.push_back(a);
    sort(v.begin(), v.end());
    unordered_map<int,int> index, visited;
    for(int i=0;i<n;++i) index[v[i]]= i;

    for(int i=0;i<n;++i){
        if(visited.find(A[i]) == visited.end()){
            // search less than value and can divid
            int idx = index[A[i]], count = 0;
            for(int j=0;j<=idx; ++j){
                if(A[i]% v[j] ==0) count++;
            }
            visited[A[i]] = n-count;
        }
        ret.push_back(visited[A[i]]);
    
    }
    return ret;
}
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(n)`