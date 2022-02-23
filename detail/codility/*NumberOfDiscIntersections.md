---
title: NumberOfDiscIntersections
categories: 
    - codility
    - sorting
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/)

## solution

- [81%] brute force => time out
用全部減去不會交集的數量

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    long total = (long)n*(n-1)/2;
    int sum = 0;
    for(int i=0;i<n-1;++i){
        for(int r = i+1;r<n;++r){
            // count non-intersection
            if (r- A[i]- i > A[r]) { //right>A[i]+i+A[right] will cause overflow
                    sum++;
                }  
        }
    }
    return total-sum;
}


```


## analysis
- brute force
    - time complexity `O(n^2)`
    - space complexity `O(1)`


