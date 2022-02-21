---
title: PassingCars
categories: 
    - codility
    - Prefix Sum
comments: false
---
## [problem](https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/)


## solution 

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    //  0   1   0   1   1
    //  0   1   1   2   3
    // count the number of one
    int ones = 0;
    for(int a:A) ones+=(a==1?1:0);
    int count = 0, n =A.size();
    for(int i=0;i<n;++i){
        if(A[i]==0){
            count+=ones;
            if(count>1000000000) return -1;
        }
        else ones--;
    }
    return count;
}
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`