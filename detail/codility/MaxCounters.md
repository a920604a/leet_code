---
title: MaxCounters
categories: 
    - codility
    - Counting Elements
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/)


## solution 
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int counter = 0, before = 0, n = A.size();
    vector<int> ret(N,0);
    for(int a:A){
        if(a!=N+1){
            // 延遲assign max counter
            if(before!=0 && ret[a-1]!=before) ret[a-1] = max(before, ret[a-1]);
            ret[a-1]++;
            // update max counter
            counter = max(counter, ret[a-1]);
        }
        else{
            before = counter;
        }
        // for(int a:ret) cout<<a<<" ";
        // cout<<endl;
    }
    // for(int a:ret) cout<<a<<" ";
    for(int &a:ret){
        a = max(a, before);
    }
    return ret;
}
```
## analysis
- time complexity `O(n+m)`, m is the number of array A
- space complexity `O(1)`


