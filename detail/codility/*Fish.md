---
title: NumberOfDiscIntersections
categories: 
    - codility
    - Stacks and Queues
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/)

## solution

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<stack>
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    //  4   3   2   1   5   
    //  <-  ->  <-  <-  <-
    // monotonic stack
    stack<int> sta;
    // 儲存往下游的魚
    int n = A.size(),  eat = 0;
    for(int i=0;i<n;++i){
        if(B[i] == 0){
            while(!sta.empty() && sta.top() < A[i]){
                // 往下游的魚被往上游的魚吃掉了
                sta.pop();
                eat++;
            }

            if(!sta.empty() && sta.top() > A[i]){
                // 往上游的魚被往下游的魚吃掉了
                eat++;
            }
            
        }
        else{
            sta.push(A[i]);
        }
    }
    return n - eat;
}

```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`


