---
title: MinAvgTwoSlice
categories: 
    - codility
    - Prefix Sum
comments: false
---
## [problem](https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/)


## solution 

#### option 1 - prefix sum 
最小區間只會存在於兩個是數字或是三個數字，因為如果有超過3個數字，代表還可以在拆分

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<vector>
#include<unordered_map>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // prefix sum
    //  4   2   2   5   1   5   8
    //  4   6   8   13  14  19  27
    int n = A.size();
    vector<int> prefix(n,0);
    unordered_map<int,int> mp;
    prefix[0] = A[0];
    for(int i=1;i<n;++i) prefix[i] = prefix[i-1] + A[i];
    int idx = 0;
    double mn = prefix[1]/2.0;
    for(int i=2;i<n;++i){
        double slice = (prefix[i]-prefix[i-2])/ 2.0;
        if( slice < mn) {
            mn = slice;
            idx = i-1;
        }
        if(i>2){
            slice = (prefix[i]-prefix[i-3])/3.0;
            if( slice< mn){
                mn = slice;
                idx = i-2;
            }
        }
    }
    return idx;}

```
#### option 2 - 最小區間只會存在於兩個是數字或是三個數字，因為如果有超過3個數字，代表還可以在拆分

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    double mn = 100000;
    int idx = -1;
    for(int i=0;i<n-1;++i){
        double slice = (A[i]+A[i+1])/2.0;
        if(slice < mn){
            mn =slice;
            idx = i;   
        }

        if(i+2<n){
            slice = (A[i] + A[i+1] + A[i+2])/3.0;
            if(slice < mn){
                mn =slice;
                idx = i;   
            }
        }
    }
    return idx;
}

```

## analysis

- time complexity `O(n)`
- space complexity `O(1)`